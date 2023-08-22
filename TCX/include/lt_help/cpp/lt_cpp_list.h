#ifndef __LT_CPP_LIST__
#define __LT_CPP_LIST__

#include <lt_help/cpp/lt_cpp_base.h>

#define FREE_LIST(list)    \
    if(list!= nullptr)     \
    {   freeList(list);    \
        list = nullptr;    \
    }


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* makeList(int num, ...)
{
    ListNode tmp(0);
    ListNode* pnode = &tmp;

    va_list valist;    
    va_start(valist, num); 
    for (int i = 0; i < num; i++)
    {
       int val = va_arg(valist, int);
       pnode->next = new ListNode(val);
       pnode=pnode->next;
    }

    va_end(valist);    

    return tmp.next;
}

void freeList(ListNode* list)
{
    ListNode* pnode = list;
    ListNode* pnext;
    while( pnode != nullptr)
    {
        pnext = pnode->next;
        delete pnode;
        pnode = pnext;
    }
}


int sizeOfList(ListNode* list)
{
    int size = 0;
    ListNode* pnode = list;
    for(ListNode* pnode = list; pnode != nullptr; pnode = pnode->next)
    {   ++size;
    }
    
    return size;
}

//template <typename T>
//void output_list(const T* output)
//{   std::cout << *output;
//}

void outputList(const ListNode* list)
{
    std::cout << "[";
    for(const ListNode* pnode = list; pnode != nullptr; pnode = pnode->next)
    {   
        if( pnode != list )
            std::cout << "->";
        std::cout << pnode->val;
    }
    
    std::cout << "]";
}

void outputList(std::vector<ListNode*>& output)
{
    std::cout << "[";
    for(int i =0 ;i < output.size(); ++i)
    {   
        if( i != 0 )
            std::cout << ",";
        outputList(output[i]);
    }
    
    std::cout << "]";
}

#endif //__LT_CPP_LIST__