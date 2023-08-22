#include "stdio.h"

int main(void)
{
    enum e1 { E1=5, E2=1, E3 };
    
    printf("E1: %d\n", E1); 
    printf("E2: %d\n", E2);
    printf("E3: %d\n", E3);
    
    printf( "output: done. \n" );
    
    return 0;
}
