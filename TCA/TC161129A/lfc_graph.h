#ifndef __LFC_EXAMPLE_GRAPH__
#define __LFC_EXAMPLE_GRAPH__

#include <stdlib.h>
#include <string.h>


#define GRAPH_TYPE_DIRECTED         1
#define GRAPH_TYPE_UNDIRECTED       2

typedef struct __Graph_Type
{
    int N;
    int Type;
    int Weight[1];
} Graph_T;

void Init_Directed_Graph(Graph_T* pGraph, int N, int* weight);
void Set_Directed_Graph_Weight(Graph_T* pGraph, int i, int j, int weight);
int  Get_Directed_Graph_Weight(Graph_T* pGraph, int i, int j);
int  Get_Directed_Graph_size(int N);
int  Print_Graph(Graph_T* pGraph);

void Init_UnDirected_Graph(Graph_T* pGraph, int N, int* weight);
void Set_UnDirected_Graph_Weight(Graph_T* pGraph, int i, int j, int weight);
int  Get_UnDirected_Graph_Weight(Graph_T* pGraph, int i, int j);


void Init_Directed_Graph(Graph_T* pGraph, int N, int* weight)
{
    int i, j, v, size;
    
    size = Get_Directed_Graph_size(N);
    memset( (void*) pGraph, 0 , (size_t) size );
    
    pGraph->N = N;
    pGraph->Type = GRAPH_TYPE_DIRECTED;
    
    for( i = 0; i < N; ++i )
    {   for( j = 0; j < N; ++j )
        {   Set_Directed_Graph_Weight( pGraph
                                     , i
                                     , j
                                     , weight[i*N+j]);
        }
    }
}

void Set_Directed_Graph_Weight(Graph_T* pGraph, int i, int j, int weight)
{
    pGraph->Weight[i*pGraph->N+j] = ( weight < 0 ? -1 : weight );
}

int Get_Directed_Graph_Weight(Graph_T* pGraph, int i, int j)
{   
    return pGraph->Weight[i*pGraph->N+j];
}

int Get_Directed_Graph_size(int N)
{   return sizeof(Graph_T) + N*N*sizeof(int);   
}

int Print_Graph(Graph_T* pGraph)
{
    int N = pGraph->N;
    int i, j, v;
    
    printf("Graph: N=%d, type=", N);
    
    switch(pGraph->Type)
    {
    case GRAPH_TYPE_DIRECTED:
        printf("directed");
        break;
    case GRAPH_TYPE_UNDIRECTED:
        printf("undirected");
        break;
    default:
        printf("unkbown");
    }
    printf("\n      ");
    
    for(j = 0; j < N; ++j)
    {   printf("  N%02d",j);
    }
    printf("\n");
    
    for(i = 0; i < N; ++i)
    {
        printf("  N%02d: ", i);
        for(j = 0; j < N; ++j)
        {   printf(" %3d,", pGraph->Weight[i*N + j]);
        }
        printf("\n");
    }
}

void Init_UnDirected_Graph(Graph_T* pGraph, int N, int* weight)
{
    int i, j, v, size;
    
    size = Get_Directed_Graph_size(N);
    memset( (void*) pGraph, 0 , (size_t) size );
    
    pGraph->N = N;
    pGraph->Type = GRAPH_TYPE_UNDIRECTED;
    
    for( i = 0; i < N - 1; ++i )
    {   for( j = i; j < N; ++j )
        {
            Set_UnDirected_Graph_Weight( pGraph
                                       , i
                                       , j
                                       , weight[i*N+j]);
        }
    }
}

void Set_UnDirected_Graph_Weight(Graph_T* pGraph, int i, int j, int weight)
{
    int v = weight < 0 ? -1 : weight;
    
    pGraph->Weight[i*pGraph->N+j] = v;
    pGraph->Weight[j*pGraph->N+i] = v;
}

int Get_UnDirected_Graph_Weight(Graph_T* pGraph, int i, int j)
{
    if( i > j )
        return Get_UnDirected_Graph_Weight(pGraph, j, i);
    
    return pGraph->Weight[i*pGraph->N+j];
}


#endif //__LFC_EXAMPLE_GRAPH__