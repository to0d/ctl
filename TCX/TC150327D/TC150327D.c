#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

/* Linux ........... /var/spool/mail/...... */
#define MAIL "/var/spool/mail/root"

#define SLEEP_TIME 1

int main(void)
{
    pid_t child;
    
    if((child=fork())==-1 )
    {
        printf("Fork Error.%s\n",strerror(errno));
        return(1);
    }
    
    
    //Parent process will loop infinitely
    if(child > 0)
    {        
        while(1);
        return 0;
    }
    
    /**********************************************/
    /* Now here is child daemon process                              
    /**********************************************/
    // kill parent
    if( kill(getppid(),SIGTERM)== -1 )
    {
        printf("Kill Parent Error.%s\n", strerror(errno) );
        return(1);
    }
    
    printf("output: done.\n");
    
    /**********************************************/
    /* Child daemon process work flow                            
    /**********************************************/
    int mailfd;
    int time = 1;
    while(time-- > 0)
    {
        if((mailfd = open(MAIL,O_RDONLY))!=-1 )
        {
           fprintf(stderr,"%s","\007");
           close(mailfd);
        }
        
        printf("Child running\n");
        sleep(SLEEP_TIME);
    }
    
    return 0;
}
