#include<stdio.h>

int main()
{
    int j = 0;
    for(int i = 0; i< 3; ++i){
        sleep(1);
        j *= 2;
        printf("Hello, i=%d!\n", i);
    }
    printf("Hello, j=%d!\n", j);
    return 0;
}

