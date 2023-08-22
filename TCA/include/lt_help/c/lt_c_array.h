#ifndef __LT_C_ARRAY__
#define __LT_C_ARRAY__

#include <lt_help/c/lt_c_base.h>

void outputArray(int* nums, int n)
{
    printf("[");
    for(int i =0 ;i < n; ++i)
    {   
        if( i != 0 )
            printf(",");
        printf("%d", nums[i]);
    }

    printf("]");
}

void outputArray2(int** nums, int m, int n)
{
    printf("[");
    for(int i =0 ;i < m; ++i)
    {
        if( i != 0 )
            printf(",");
        printf("[");
        for(int j =0 ;j < n; ++j)
        {
            if( j != 0 )
                printf(",");
            printf("%d", nums[i][j]);
        }
        printf("]");
    }

    printf("]");
}

void outputArray3(char** board, int m, int n)
{
    printf("[");
    for(int i =0 ;i < m; ++i)
    {
        if( i != 0 )
            printf(",");
        printf("[");
        for(int j =0 ;j < n; ++j)
        {
            if( j != 0 )
                printf(",");
            printf("%c", board[i][j]);
        }
        printf("]");
    }

    printf("]");
}

void outputArray4(char** tokens, int size)
{
    printf("[");
    for(int i =0 ;i < size; ++i)
    {
        if( i != 0 )
            printf(",");
        printf("%s", tokens[i]);
    }

    printf("]");
}
          
#endif //__LT_C_ARRAY__