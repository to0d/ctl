#include <stdio.h>
#include <malloc.h>

int main()
{
  int *p = malloc(32);
  free(p);
  printf("return.\n");
  return 0;
}