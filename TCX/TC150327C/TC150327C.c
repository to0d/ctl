#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc,char **argv)
{
    pid_t my_pid,parent_pid;
    uid_t my_uid,my_euid;
    gid_t my_gid,my_egid;
    struct passwd *my_info;
    
    my_pid=getpid();
    parent_pid=getppid();
    my_uid=getuid();
    my_euid=geteuid();
    my_gid=getgid();
    my_egid=getegid();
    my_info=getpwuid(my_uid);
    
    printf("%-20s%ld\n", "Process ID:", my_pid);
    printf("%-20s%ld\n", "Parent ID:",parent_pid);
    printf("%-20s%ld\n", "User ID:",my_uid);
    printf("%-20s%ld\n", "Effective User ID:",my_euid);
    printf("%-20s%ld\n", "Group ID:",my_gid);
    printf("%-20s%ld\n", "Effective Group ID:",my_egid);
    
    if(my_info)
    {
        printf("%-20s%s\n", "My Login Name", my_info->pw_name);
        printf("%-20s%s\n", "My Password:", my_info->pw_passwd);
        printf("%-20s%ld\n", "My User ID:", my_info->pw_uid);
        printf("%-20s%ld\n", "My Group ID:", my_info->pw_gid);
        printf("%-20s%s\n", "My Real Name:", my_info->pw_gecos);
        printf("%-20s%s\n", "My Home Dir:", my_info->pw_dir);
        printf("%-20s%s\n", "My Work Shell:", my_info->pw_shell);
        printf("output: done.\n");
    }
    else
    {
        printf("output: !error");
    }
    
}

