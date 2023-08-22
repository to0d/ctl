#include "stdio.h"
#include <unistd.h>
int main( void )
{
    printf("Sleep 1 second\n");
    sleep(1);
    
    printf("Sleep 1000 microsecond,  1000 microseconds is equal to 1 millisecond.\n");
    usleep(1000);
    
    printf("output: done.\n");
    
    return 0;
}
