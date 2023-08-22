#include "stdio.h"
            
int main(void)
{
    printf("%-16s: %ld\n","char", sizeof(char));
    printf("%-16s: %ld\n","signed char", sizeof(signed char));
    printf("%-16s: %ld\n","unsigned char", sizeof(unsigned char));

    printf("%-16s: %ld\n","short", sizeof(short));
    printf("%-16s: %ld\n","signed short", sizeof(signed short));
    printf("%-16s: %ld\n","unsigned short", sizeof(unsigned short));

    printf("%-16s: %ld\n","int", sizeof(int));
    printf("%-16s: %ld\n","signed int", sizeof(signed int));
    printf("%-16s: %ld\n","unsigned int", sizeof(unsigned int));
    printf("%-16s: %ld\n","long int", sizeof(long int));
    printf("%-16s: %ld\n","short int", sizeof(short int));

    printf("%-16s: %ld\n","float", sizeof(float));
    printf("%-16s: %ld\n","double", sizeof(double));
    printf("%-16s: %ld\n","long double", sizeof(long double));

    printf( "output: done. \n" );
    
    return 0;
}
