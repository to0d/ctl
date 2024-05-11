#include <stdio.h>

void f1();
void f2();

int foo() {
  int i,j,k , t= 0;
  for(i=0;i<2;i++){
    for(j=0;j<3;j++)
      t++;
    f1();
  }
  f2();
  return t;
}
				

