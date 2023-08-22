#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(void)
{
    pid_t child;
    int status;
    printf("This will demostrate how to get child status\n");
    
    // function fork
    //-1:      invoke fork fail
    // 0:      This is child process
    // other:  This is parent process
    if((child=fork())==-1)
    {
        printf("Fork Error :%s\n",strerror(errno));
        return(1);
    }
    
    //Child process
    if( child == 0 )
    {
        int i;
        printf("Child: %ld\n",getpid());
        for(i=0;i<1000000;i++) sin(i);
        
        i=5;
        printf("Child: exit with %d\n",i);
        return(i);
    }
    
   
    // function: wait
    // wait ϵͳ���û�ʹ����������ֱ��һ���ӽ��̽��������Ǹ����̽��ܵ���һ���ź�
    // ���û�и�����û���ӽ��̻��������ӽ����Ѿ�������wait ����������
    // �ɹ������ӽ��̵�ID,���򷵻�-1
    // errno == EINTR �ж�
    
    //parent process wait the end of child process
    printf("Parent: waiting the end of child\n");
    while(((child = wait(&status))== -1 ) & ( errno == EINTR))
        ;
    
    if(child == -1 )
    {
        printf("Parent: Wait Error.%s\n",strerror(errno));
    }        
    else if(!status)
    {
        printf("Parent: Child %ld terminated normally return status is zero\n", child);
    }
    else if(WIFEXITED(status))
    {
        printf("Parent: Child %ld terminated normally return status is %d\n",child,WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status))
    {
        printf("Parent: Child %ld terminated due to signal %d znot caught\n",child,WTERMSIG(status));            
    }
    
    printf("output: done.\n");

    return 0;
}

