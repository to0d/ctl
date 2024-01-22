#include "stdio.h"

int main()
{
#define XXX printf
#pragma hpcc
    return 0;
}

