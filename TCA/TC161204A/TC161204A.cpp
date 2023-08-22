#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compress_Ascii_By_Huffman_Tree
        ( const char* inputText
        , int         inputLen
        , char*       outputBuffer
        , int         outputLen);

typedef struct __HUFFMAN_COMPRESS_FILE_KEY_ENTRY_TYPE
{
    unsigned short EntryLength;         // Bytes
    unsigned short BitCount;            // Bit Count
    unsigned char  Key;                 // Key
    char           BitValue[1];         // Value
} HCF_KEYENTRY_T;

typedef struct __HUFFMAN_COMPRESS_FILE_HEADER_TYPE
{
    unsigned long TotalLengh;
    unsigned long HeadLength;
    unsigned long CharCount;    
    unsigned long OffsetOfKeyMap;
    unsigned long OffsetOfContent;
    
} HCF_HEADER_T;
        
typedef struct __HUFFMAN_TREE_NODE HFT_NODE_T;
struct __HUFFMAN_TREE_NODE
{
    HFT_NODE_T*     pLeft;
    HFT_NODE_T*     pRight;
    unsigned long   Weight;
    unsigned char   Character;
};

void Print_HF_Tree(HFT_NODE_T* pTree);
void Free_HF_Tree(HFT_NODE_T* pTree);
void Print_HF_Tree_Encode(HFT_NODE_T* pTree);

HFT_NODE_T* Build_HF_Tree(HFT_NODE_T** array, int num);

int main( void )
{
    char inputText[] = {"The ATC Code Coverage tool currently supports PL/X, C and C++ on System i5 systems"};
    char buffer[4096];
    
    printf("Input: %s\n",inputText);
    
    int encodeLength = Compress_Ascii_By_Huffman_Tree( inputText
                                                     , strlen(inputText)
                                                     , buffer
                                                     , sizeof(buffer));

                                                     
    printf("output: encodeLength: %d\n",encodeLength);
    
    return 0;
}


int Compress_Ascii_By_Huffman_Tree
        ( const char* inputText
        , int         inputLen
        , char*       outputBuffer
        , int         outputLen)
{
    
//#define _DBUG
    
    int charCount[256];
    unsigned char keyArray[256];
    HFT_NODE_T* pTreeNodeArray[256];
    
    int encodeLength = 0;
    int keyCount = 0;
    int TreeNodeCount = 0;
    unsigned char c;
    int i;
    
    memset(charCount, 0 , sizeof(charCount));
    
    for( i = 0; i < inputLen; ++i)
    {   c = (unsigned char) inputText[i];
        charCount[c]++;         
    }

    for( i = 0; i < 256; ++i)
    {   if( charCount[i] > 0 )
        {  keyArray[keyCount++] = (unsigned char)i;
    
           HFT_NODE_T* pNode    = (HFT_NODE_T*)malloc(sizeof(HFT_NODE_T));
           memset(pNode, 0 , sizeof(HFT_NODE_T));
           pNode->Character     = (unsigned char)i;
           pNode->Weight        = charCount[i];
           pTreeNodeArray[TreeNodeCount++] = pNode;
        }
    }
#ifdef _DBUG 
    printf("Keys:\t");
    for( i = 0; i < keyCount; ++i )
    {   printf("'%c':%d,", keyArray[i], charCount[keyArray[i]]);  
    }
    printf("\n");
#endif

    /* ************************************************ */
    /*                                                  */
    /* Build The Huffman Tree by HeapSort               */
    /*                                                  */
    /*                                                  */
    /* ************************************************ */

#ifdef _DBUG 
    printf("Before Build HF Tree:\n");
    for( i = 0; i < TreeNodeCount; ++i )
    {   
        printf("T%02d: ", i);
        Print_HF_Tree(pTreeNodeArray[i]);
        printf("\n");
    }    
#endif

    HFT_NODE_T* pHFTree = Build_HF_Tree(pTreeNodeArray, TreeNodeCount);
#ifdef _DBUG 
    printf("HF Tree:");
    Print_HF_Tree(pHFTree);
    printf("\n");
#endif

    printf("HF Tree Encode:\n");
    Print_HF_Tree_Encode(pHFTree);

    Free_HF_Tree(pHFTree);
    return 0;
}

void _Print_HF_Tree2(HFT_NODE_T* pTree, char* buf, int length)
{
    int i;
    
    if( pTree == NULL )
    {   return;        
    }
    
    if( pTree->pLeft == NULL || pTree->pRight == NULL)
    {
        buf[length] = '\0';
        printf("'%c': [%s]\n", pTree->Character, buf);          
        return;
    }
    
    buf[length] = '0';
    _Print_HF_Tree2(pTree->pLeft, buf, length+1);
    
    buf[length] = '1';
    _Print_HF_Tree2(pTree->pRight, buf, length+1);
}


void Print_HF_Tree_Encode(HFT_NODE_T* pTree)
{
    char buf[256];
    _Print_HF_Tree2(pTree, buf, 0);
}

void Print_HF_Tree(HFT_NODE_T* pTree)
{
    if(pTree == NULL)
    {   
        printf("nil,");
        return;        
    }
    
    printf("[%c,%l],", pTree->Character, pTree->Weight);
    Print_HF_Tree(pTree->pLeft);
    Print_HF_Tree(pTree->pRight);
}


void Free_HF_Tree(HFT_NODE_T* pTree)
{
    if(pTree == NULL)
    {   return;        
    }
    
    Free_HF_Tree(pTree->pLeft);
    Free_HF_Tree(pTree->pRight);
    free(pTree);
}

void Heap_Adjust_Tree(HFT_NODE_T** array, int s, int m)
{
    if( ( 2*s + 1) > m )
    {   return;        
    }
    
    HFT_NODE_T* pGuard = array[s]; 
    int count = 0;
    int j = 2*s + 1;
    
    while( j <= m  )
    {
        if( j < m && (array[j]->Weight) > (array[j+1]->Weight) ) 
        {    ++j;            
        }

        if( pGuard->Weight <= (array[j]->Weight) )
        {   break;
        }
        
        array[s] = array[j];
        ++count;
        s = j;
        j = 2*j+1;
    }
    
    if( count > 0 ) 
    {    array[s] = pGuard;        
    }
}

HFT_NODE_T* Build_HF_Tree(HFT_NODE_T** array, int num)
{
    int i, len;
    HFT_NODE_T *pMin1, *pMin2, *pNew;
    
    for (i = num/2; i >= 0; --i)
    {   Heap_Adjust_Tree(array, i, num-1 );
    }
    
   
    for(len = num; len > 1; --len )
    {
        pMin1    = array[0];
        array[0] = array[len-1];
        array[len-1] = NULL;
        
        Heap_Adjust_Tree(array, 0, len-2 );
        pMin2    = array[0];

        pNew     = (HFT_NODE_T*)malloc(sizeof(HFT_NODE_T));
        memset(pNew, 0 , sizeof(HFT_NODE_T));
        
        pNew->Weight = pMin1->Weight + pMin2->Weight;
        pNew->pLeft  = pMin1;
        pNew->pRight = pMin2;
        
        array[0] = pNew;
        
        Heap_Adjust_Tree(array, 0, len-2 );
    }
    
    return array[0];
}