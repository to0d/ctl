/* Code sample: using ptrace for simple tracing of a child process.
**
** Eli Bendersky (http://eli.thegreenplace.net)
** This code is in the public domain.
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>
#include <syscall.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

struct debug_breakpoint_t {
    void* addr;
    unsigned orig_data;
};

typedef struct debug_breakpoint_t debug_breakpoint;

long get_child_eip(pid_t pid);
debug_breakpoint* create_breakpoint(pid_t pid, void* addr);
void cleanup_breakpoint(debug_breakpoint* bp);
int resume_from_breakpoint(pid_t pid, debug_breakpoint* bp);

/* Print a message to stdout, prefixed by the process ID
*/
void procmsg(const char* format, ...)
{
    va_list ap;
    fprintf(stdout, "[%d] ", getpid());
    va_start(ap, format);
    vfprintf(stdout, format, ap);
    va_end(ap);
}


void run_target(const char* programname)
{
    procmsg("target started. will run '%s'\n", programname);

    /* Allow tracing of this process */
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
        perror("ptrace");
        return;
    }

    /* Replace this process's image with the given program */
    execl(programname, programname, 0);
}


void run_debugger(pid_t child_pid)
{
    int wait_status;
    unsigned icounter = 0;
    procmsg("debugger started\n");

    /* Wait for child to stop on its first instruction */
    wait(0);    
    procmsg("child now at EIP = 0x%08X\n", get_child_eip(child_pid));

    /* Create breakpoint and run to it*/
    debug_breakpoint* bp = create_breakpoint(child_pid, (void*)(0x401f6e));
    procmsg("breakpoint created\n");
    ptrace(PTRACE_CONT, child_pid, 0, 0);
    wait(0);

    long stop_addr = get_child_eip(child_pid);
    procmsg("child stopped at breakpoint. EIP = 0x%08X\n", stop_addr);
   
    sleep(10);
    
    int rc = resume_from_breakpoint(child_pid, bp);
    procmsg("resume_from_breakpoint: rc=%d\n", rc);
    
    
    cleanup_breakpoint(bp);
}


int main(int argc, char** argv)
{
    pid_t child_pid;

    if (argc < 2) {
        fprintf(stderr, "Expected a program name as argument\n");
        return -1;
    }

    child_pid = fork();
    if (child_pid == 0)
        run_target(argv[1]);
    else if (child_pid > 0)
        run_debugger(child_pid);
    else {
        perror("fork");
        return -1;
    }

    return 0;
}





long get_child_eip(pid_t pid)
{
    struct user_regs_struct regs;
    ptrace(PTRACE_GETREGS, pid, 0, &regs);
    return regs.rip;
}

/* Enable the given breakpoint by inserting the trap instruction at its 
** address, and saving the original data at that location.
*/
static void enable_breakpoint(pid_t pid, debug_breakpoint* bp)
{
    assert(bp);
    bp->orig_data = ptrace(PTRACE_PEEKTEXT, pid, bp->addr, 0);
    ptrace(PTRACE_POKETEXT, pid, bp->addr, (bp->orig_data & ~0xFF) | 0xCC);
        
    unsigned readback_data = ptrace(PTRACE_PEEKTEXT, pid, bp->addr, 0);
    procmsg( "enable_breakpoint instruction= 0x%08X, old=0x%08X, new=0x%08X\n"
           , bp->addr
           , bp->orig_data
           , readback_data);
}

/* Disable the given breakpoint by replacing the byte it points to with
** the original byte that was there before trap insertion.
*/
static void disable_breakpoint(pid_t pid, debug_breakpoint* bp)
{
    assert(bp);
    long data = ptrace(PTRACE_PEEKTEXT, pid, bp->addr, 0);
    assert((data & 0xFF) == 0xCC);
    ptrace(PTRACE_POKETEXT, pid, bp->addr, (data & ~0xFF) | (bp->orig_data & 0xFF));

    unsigned readback_data = ptrace(PTRACE_PEEKTEXT, pid, bp->addr, 0);
    procmsg( "disable_breakpoint instruction= 0x%08X, old=0x%08X, new=0x%08X\n"
           , bp->addr
           , data
           , readback_data);
}


debug_breakpoint* create_breakpoint(pid_t pid, void* addr)
{
    procmsg("create_breakpoint at 0x%08X\n", addr);
    debug_breakpoint* bp = malloc(sizeof(*bp));
    bp->addr = addr;
    enable_breakpoint(pid, bp);
    return bp;
}

void cleanup_breakpoint(debug_breakpoint* bp)
{
    free(bp);
}


int resume_from_breakpoint(pid_t pid, debug_breakpoint* bp)
{
    struct user_regs_struct regs;
    int wait_status;
    
    procmsg("resume_from_breakpoint at EIP = 0x%08X\n", get_child_eip(pid));


    ptrace(PTRACE_GETREGS, pid, 0, &regs);
    /* Make sure we indeed are stopped at bp */
    assert(regs.rip == (long) bp->addr + 1);

    /* Now disable the breakpoint, rewind EIP back to the original instruction
    ** and single-step the process. This executes the original instruction that
    ** was replaced by the breakpoint.
    */
    regs.rip = (long) bp->addr;
    ptrace(PTRACE_SETREGS, pid, 0, &regs);
    disable_breakpoint(pid, bp);
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) < 0) {
        perror("ptrace");
        return -1;
    }
    wait(&wait_status);

    if (WIFEXITED(wait_status)) {
        return 0;
    }
    
    procmsg("\tresume at EIP = 0x%08X\n", get_child_eip(pid));

    /* Re-enable the breakpoint and let the process run.
    */
    enable_breakpoint(pid, bp);

    if (ptrace(PTRACE_CONT, pid, 0, 0) < 0) {
        perror("ptrace");
        return -1;
    }
    wait(&wait_status);
    
    if (WIFEXITED(wait_status))
        return 0;
    else if (WIFSTOPPED(wait_status)) {
        return 1;
    }
    else
        return -1;
}
