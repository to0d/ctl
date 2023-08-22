#ifndef __LT_C_STRING__
#define __LT_C_STRING__

#include <lt_help/c/lt_c_base.h>

char* makeString(const char* s)
{   
    char* ss = malloc(strlen(s)+1);
    strcpy(ss,s);
    return ss;
}


#endif //__LT_C_STRING__