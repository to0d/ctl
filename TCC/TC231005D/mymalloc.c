#ifdef RUNTIME

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *malloc(size_t size)
{
  static int flag = 1;  //flag 1：打印，0：不打印
  void *(*mallocp)(size_t size);
  char *error;
  //获取libc中malloc的地址
  mallocp = dlsym(RTLD_NEXT,"malloc");
  if((error = dlerror()) != NULL)
  {
    fputs(error,stderr);
    exit(1);
  }
  char *ptr = mallocp(size);
  if(flag == 1)
  {
    flag = 0;
    printf("malloc(%d) = %p\n", (int)size,ptr);
  }
  flag = 1;
  return ptr;
}

void free(void *ptr)
{
  static int flag = 1;  //flag 1：打印，0：不打印
  void (*freep)(void *) = NULL;
  char *error;
  if(!ptr)
    return;
  //获取libc中free的地址
  freep = dlsym(RTLD_NEXT, "free");
  if((error = dlerror())!=NULL)
  {
    fputs(error,stderr);
    exit(1);
  }
  freep(ptr);
  if(flag == 1)
  {
    flag = 0;
    printf("free(%p)\n",ptr);
  }
  flag = 1;
}

#endif