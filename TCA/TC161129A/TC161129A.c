#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lfc_graph.h"

typedef int (*visit_fun_t)(Graph_T*, int);

int  Is_Graph_All_Conneted(Graph_T* pGraph);
void Visit_Directed_Graph_DepthFirst(Graph_T* pGraph, visit_fun_t vfun);
void Visit_Directed_Graph_BreadthFirst(Graph_T* pGraph, visit_fun_t vfun);
int  Search_Directed_Graph_DepthFirst_From(Graph_T* pGraph, visit_fun_t vfun, int from);
int  Search_Directed_Graph_BreadthFirst_From(Graph_T* pGraph, visit_fun_t vfun, int from);
int  Get_UnDirected_Graph_Girth(Graph_T* pGraph, int* pPath);

int Search_Graph_PrintIndex(Graph_T* pGraph, int index)
{   
    printf("%d,", index);
    return 0;
}

int main( void )
{
    {
        printf("******************** Graph 1 ********************\n");
        
        int g1[7][7] = 
        {
            {  0 ,100,  10,  30, -1, -1, -1, }, 
            {  -1,  0,  -1,  -1, -1, -1, -1, }, 
            {  -1, -1,   0,  -1, 20, -1, -1, }, 
            {  -1, 10,  -1,   0,  8, -1, -1, }, 
            {  -1,  5,  -1,  -1,  0, -1, -1, }, 
            {  -1,  -1, -1,  -1, -1,  0, 10, }, 
            {  -1,  -1, -1,  -1, -1, -1,  0, }, 
        };

        char temp[sizeof(g1)*2];
        Graph_T* pGraph = (Graph_T*) temp;
        
        Init_Directed_Graph(pGraph, 7, (int*)(&(g1[0][0])));
        Print_Graph(pGraph);
        
        //判断图是否连通
        printf("Is_Graph_All_Conneted: ");
        if( Is_Graph_All_Conneted(pGraph) )
        {   printf("Yes\n");
        }
        else
        {   printf("No\n");
        }
        
        // 图搜索
        printf("Search_DepthFirst_From: ");
        Search_Directed_Graph_DepthFirst_From(pGraph, &Search_Graph_PrintIndex, 0);
        printf("\n");
        
        printf("Search_BreadthFirst_From: ");
        Search_Directed_Graph_BreadthFirst_From(pGraph, &Search_Graph_PrintIndex, 0);
        printf("\n");
        
        printf("Visit_DepthFirst: ");
        Visit_Directed_Graph_DepthFirst(pGraph, &Search_Graph_PrintIndex);
        printf("\n");
        
        printf("Visit_BreadthFirst: ");
        Visit_Directed_Graph_BreadthFirst(pGraph, &Search_Graph_PrintIndex);
        printf("\n");
        
        // 图中间环的检测
        
        
    }
    {
        printf("******************** Graph 2 ********************\n");
        /*                               */
        /*                               */
        /*      (0) ------- (1)          */
        /*      / \          |           */
        /*     /   \         |           */
        /*    /     \        |           */
        /*  (4)-----(3)-----(2)          */
        /*                               */
        
        int g2[5][5] = 
        {
            { 0, 1, 0, 1, 1, }, 
            { 0, 0, 1, 0, 0, }, 
            { 0, 0, 0, 1, 0, }, 
            { 0, 0, 0, 0, 1, }, 
            { 0, 0, 0, 0, 0, }, 
        };
        
        char temp[sizeof(g2)*2];
        Graph_T* pGraph = (Graph_T*) temp;
        
        Init_UnDirected_Graph(pGraph, 5, (int*)(&(g2[0][0])));
        Print_Graph(pGraph);
        
        printf("Visit_DepthFirst: ");
        Visit_Directed_Graph_DepthFirst(pGraph, &Search_Graph_PrintIndex);
        printf("\n");
        
        printf("Get_UnDirected_Graph_Girth: ");
        int GirthPath[5];
        int nGirth = Get_UnDirected_Graph_Girth(pGraph, GirthPath);
        printf("Girth=%d, Path=", nGirth);
        
        int i = 0;
        while( i < nGirth )
        {   printf("%d,", GirthPath[i++]);
        }
        
        printf("\n");
        
    }
    
    printf("output: done!\n");
    
    return 0;
}



int _Search_Directed_Graph_DepthFirst(Graph_T* pGraph
                                     , visit_fun_t vfun
                                     , int index
                                     , char* pSearched
                                     , int* found)
{
    int N           = pGraph->N;
    int nSearched    = 0;
    int i, next;
    
    *found = vfun(pGraph, index);
    nSearched++;
    pSearched[index] = 1;
    
    for( i = 0; (*found == 0) && i < N; ++i )
    {
        if( pSearched[i] == 0
         && Get_Directed_Graph_Weight(pGraph, index, i ) >= 0 ) 
        {   nSearched += _Search_Directed_Graph_DepthFirst(pGraph, vfun, i, pSearched, found);
        }
    }
    
    return nSearched;
}


int Search_Graph_None(Graph_T* pGraph, int index)
{   
    // printf("Search %d\n", index);
    return 0;
}

int Is_Graph_All_Conneted(Graph_T* pGraph)
{
    return Search_Directed_Graph_DepthFirst_From(pGraph, &Search_Graph_None, 0) == pGraph->N;
}

int Search_Directed_Graph_DepthFirst_From(Graph_T* pGraph, visit_fun_t vfun, int from)
{
    int N = pGraph->N;
    
    if( from < 0 || from >= N )
    {   return 0;
    }
    
    char* pSearched = (char*) malloc(N);
    memset( pSearched, 0, N );
 
  
    int nSearched  = 0;
    int found     = 0;
    nSearched = _Search_Directed_Graph_DepthFirst(pGraph, vfun, from, pSearched, &found);
    
    free(pSearched);
    return nSearched;
}


int Search_Directed_Graph_BreadthFirst_From(Graph_T* pGraph, visit_fun_t vfun, int from)
{
    int N = pGraph->N;
    
    if( from < 0 || from >= N )
    {   return 0;
    }
    
    char* pSearched = (char*) malloc(N);
    memset( pSearched, 0, N );

    int* pQueue = (int*) malloc(N*sizeof(int));
    memset( pQueue, 0, N*sizeof(int));
  
    int nSearched    = 0;
    int found       = 0;
    int nQueueLengh = 0;
    int nQueueIndex = 0;
    int index, i;
    
    pQueue[nQueueLengh++] = from;
    pSearched[from] = 1;
    
    while( ( found == 0 ) && (nQueueIndex < nQueueLengh) )
    {   
        index = pQueue[nQueueIndex++];
        found = vfun(pGraph, index);
        nSearched++;
        
        for( i = 0; ( found == 0) && i < N; ++i )
        {
            if( pSearched[i] == 0
             && Get_Directed_Graph_Weight(pGraph, index, i ) >= 0 ) 
            {
                pQueue[nQueueLengh++] = i;
                pSearched[i] = 1;
            }
        }
    }

    free(pSearched);
    free(pQueue);
    return nSearched;
}

void Visit_Directed_Graph_DepthFirst(Graph_T* pGraph, visit_fun_t vfun)
{
    int N = pGraph->N;
    
    char* pSearched = (char*) malloc(N);
    memset( pSearched, 0, N );
 
    int nSearched  = 0;
    int found      = 0;
    int from       = 0;
    
    while( from < N && nSearched < N )
    {
        if( pSearched[from] != 0 )
        {   ++from;
            continue;
        }
        
        nSearched += _Search_Directed_Graph_DepthFirst(pGraph, vfun, from, pSearched, &found);
        ++from;
    }
    
    free(pSearched);
}

void Visit_Directed_Graph_BreadthFirst(Graph_T* pGraph, visit_fun_t vfun)
{
    int N = pGraph->N;
    
    char* pSearched = (char*) malloc(N);
    memset( pSearched, 0, N );

    int* pQueue = (int*) malloc(N*sizeof(int));
    memset( pQueue, 0, N*sizeof(int));
  
    int nSearched    = 0;
    int found       = 0;
    int nQueueLengh = 0;
    int nQueueIndex = 0;
    int from        = 0;
    int index, i;

    while( from < N && nSearched < N )
    {
        if( pSearched[from] != 0 )
        {   ++from;
            continue;
        }
        
        pQueue[nQueueLengh++] = from;
        pSearched[from] = 1;
    
        while( ( found == 0 ) && (nQueueIndex < nQueueLengh) )
        {   
            index = pQueue[nQueueIndex++];
            found = vfun(pGraph, index);
            nSearched++;
            
            for( i = 0; ( found == 0) && i < N; ++i )
            {
                if( pSearched[i] == 0
                 && Get_Directed_Graph_Weight(pGraph, index, i ) >= 0 ) 
                {
                    pQueue[nQueueLengh++] = i;
                    pSearched[i] = 1;
                }
            }
        }
    }

    free(pSearched);
    free(pQueue);
}

void _Get_UnDirected_Graph_Girth_DepthFirst(Graph_T* pGraph
                                          , int     index
                                          , char*   pSearched
                                          , int     depth
                                          , int*    pVisitPath
                                          , int*    pHistoryIndex
                                          , int*    pGirthLength
                                          , int*    pGirthPath)
{
    int N = pGraph->N;
    int i , d, k, next;
    
    pSearched [index]    = 1;
    pVisitPath[depth-1]  = index;
    pHistoryIndex[index] = depth;
    
    for( i = 0; i < N; ++i )
    {
        if( i == index || Get_Directed_Graph_Weight(pGraph, index, i ) <= 0) 
        {   continue;
        }
        
        if( pSearched[i] == 0 )
        {   _Get_UnDirected_Graph_Girth_DepthFirst( pGraph
                                                  , i
                                                  , pSearched
                                                  , depth+1
                                                  , pVisitPath
                                                  , pHistoryIndex
                                                  , pGirthLength
                                                  , pGirthPath);
        }
        else if( pHistoryIndex[i] != 0 && pVisitPath[depth-2] != i)
        {
            int girth = depth - pHistoryIndex[i] + 1;
            if( *pGirthLength == -1 || *pGirthLength > girth )
            {
                *pGirthLength = girth;
                d = pHistoryIndex[i];
                k = 0;
                
                while( d <= depth )
                {   pGirthPath[k] = pVisitPath[d-1]; 
                    ++d;
                    ++k;
                }
            }
        }
    }
    
    pHistoryIndex[index] = 0;
}

int Get_UnDirected_Graph_Girth(Graph_T* pGraph, int* pPath)
{
        
    int N = pGraph->N;
    int GirthLength = -1;
    
    char* pSearched = (char*) malloc(N);
    memset( pSearched, 0, N );

    int* pVisitPath = (int*) malloc(N*sizeof(int));
    memset( pVisitPath, 0, N*sizeof(int));
  
    int* pHistoryIndex = (int*) malloc(N*sizeof(int));
    memset( pHistoryIndex, 0, N*sizeof(int));
    
    int i = 0;
    while ( i < N )
    {
        memset( pSearched, 0, N );
        _Get_UnDirected_Graph_Girth_DepthFirst( pGraph
                                              , i++
                                              , pSearched
                                              , 1
                                              , pVisitPath
                                              , pHistoryIndex
                                              , &GirthLength
                                              , pPath);
    }
    
    free(pSearched);
    free(pVisitPath);
    free(pHistoryIndex);
    return GirthLength;
}