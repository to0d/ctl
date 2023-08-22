#include <iostream>
#include <stdio.h>
using namespace std;

extern int ext_x2;
extern int ext_fun3();

//变量
//局部变量  ==> 栈
//static    ==> 静态数据区
//register  ==>CPU
//extern    全局访问

int main(void)
{
    register int b = 0;
    
    printf("%-30s: %-10s= %d\n","register int b = 0", "++b", ++b);
    printf("%-30s: %-10s= %d\n","extern int ext_x2", "++ext_x2", ++ext_x2);
    printf("%-30s: %-10s= %d\n","extern int ext_fun3()", "ext_fun3()", ext_fun3());
    
    std::cout << "output: done!" << endl;
   
    return 0;
}

