#ifndef __LT_C_LIST__
#define __LT_C_LIST__

#include <lt_help/c/lt_c_base.h>

#define FREE_LIST(list)    \
    if(list!= NULL)     \
    {   freeList(list);    \
        list = NULL;    \
    }

#define FREE_POINTER(p) \
    if(p!= NULL)        \
    {   free(p);        \
        list = NULL;    \
    }
    
    
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int num, ...)
{
    struct ListNode tmp;
    struct ListNode* pnode = &tmp;

    va_list valist;    
    va_start(valist, num); 
    for (int i = 0; i < num; i++)
    {
       int val = va_arg(valist, int);
       pnode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
       pnode=pnode->next;
       pnode->next = NULL;
       pnode->val = val;
    }

    va_end(valist);    

    return tmp.next;
}

void freeList(struct ListNode* list)
{
    struct ListNode* pnode = list;
    struct ListNode* pnext;
    while( pnode != NULL)
    {
        pnext = pnode->next;
        free(pnode);
        pnode = pnext;
    }
}

int sizeOfList(struct ListNode* list)
{
    int size = 0;
    struct ListNode* pnode = list;
    
    for(; pnode != NULL; pnode = pnode->next)
    {   ++size;
    }
    
    return size;
}

void outputList(struct ListNode* list)
{
    struct ListNode* pnode = list;

    printf("[");
    for(; pnode != NULL; pnode = pnode->next)
    {
        if( pnode != list )
            printf("->");
        printf("%d",pnode->val);
    }    
    printf("]");
}


#endif //__LT_C_LIST__