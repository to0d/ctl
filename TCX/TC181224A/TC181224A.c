#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
    int RandomNumber = 0;
    int i;
    
    for( i = 0 ;i < 3 ; ++i)
    {
        RandomNumber = rand() % 1000;
        printf ( "Random: %d\n", RandomNumber);
    }
    
    printf("output: done.\n");
}

