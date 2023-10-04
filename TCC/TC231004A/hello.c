#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fun.h"

int main()
{
    int zzz = 0;
    zzz += 2 + global_var;
    zzz += fun1(zzz);
    
    printf("xxx=%d\n", zzz);
    printf("output: done!\n");

    return 0;
}

