#include "stdio.h"

typedef union _X
{
    int x;
    char y[4];
} X;

// Little-Endian output
// 
// x.x=11223344
// x.y=44332211

int main(void)
{
    {
        X x;
        x.x = 0x11223344;
        
        printf("x.x=%x\n", x.x);
        printf("x.y=%x%x%x%x\n", x.y[0], x.y[1], x.y[2], x.y[3] );    
    }

    {
                
        int i = 1;
        char *p = (char*)(&i);
        
        if( *p == 1)
            printf( "output: Little Endian.\n");
        else
            printf( "output: Big Endian. \n" );
    }
    
    return 0;
}
