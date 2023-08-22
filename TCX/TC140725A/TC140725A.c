#include "stdio.h"
            
int fun()
{
    return 4;
}

int main(void)
{
    int  x1 = 1;
    int  x3[] = {3};
    char x5[2][2][2] = {"2","3","4","5"};
    
    const int x6 = 6;
          int x7 = 7;
    const int x8 = 8;
    
    int  *p1    = &x1;          // 普通指针
    int **p2    = &p1;          // 二级指针
    int(*p3)[1] = &x3;          // 指向一维数组的指针
    int (*p4)() = fun;          // 指向函数的指针
    char (*p5)[2][2][2] = &x5;  // 指向多维数组的指针
    char* p5_2 = **x5;          // 指向某数组首元素地址的指针
    
    const int *p6 = &x6;        // 指向常量(const)的指针, 变量也不可变
    int * const p7 = &x7;       // 常量指针, 指针不可变
    const int * const p8 = &x8; // 指针不可变，变量也不可变
    
    printf( "output: done. \n" );
  
    return 0;
}