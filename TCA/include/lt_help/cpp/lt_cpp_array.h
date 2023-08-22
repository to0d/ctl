#ifndef __LT_CPP_ARRAY__
#define __LT_CPP_ARRAY__

#include <lt_help/cpp/lt_cpp_base.h>

void outputArray(int* nums, int n)
{
    printf("[");
    for(int i =0 ;i < n; ++i)
    {   
        if( i != 0 )
            printf(",");
        printf("%d", nums[i]);
    }

    printf("]");
}
       
template<typename T, size_t N1> 
void outputArray(const std::array<T, N1>& arr)
{
    std::cout << "[";
    for(int i = 0; i < N1; ++i)
    {   if( i != 0 )
            std::cout << ", ";
        std::cout << arr[i]; 
    }
    std::cout << "]";
}

template<typename T, size_t N1> 
void outputArray(const T( &arry)[N1] )
{    
    std::cout << "[";    
    for(int i = 0; i < N1; ++i)
    {
        if( i != 0)
            std::cout << ", "; 
        std::cout << arry[i]; 
    }
    std::cout << "]"; 
}


template<typename T, size_t N1, size_t N2> 
void outputArray(const T( &arry)[N1][N2] )
{
    std::cout << "[";
    for(int i = 0; i < N1; ++i)
    {
        if( i != 0)
            std::cout << ", ";
        std::cout << "[";
        for(int j = 0; j < N2; ++j)
        {
            if( j != 0)
                std::cout << ", ";
            std::cout << arry[i][j]; 
        }
        std::cout << "]"; 
    }
    std::cout << "]"; 
}

template<typename T, size_t N1, size_t N2, size_t N3> 
void outputArray(const T( &arry)[N1][N2][N3] )
{    
    std::cout << "[";
    for(int i = 0; i < N1; ++i)
    {
        if( i != 0)
            std::cout << ", ";
        std::cout << "[";
        for(int j = 0; j < N2; ++j)
        {
            if( j != 0)
                std::cout << ", ";
            std::cout << "[";
            for(int k = 0; k < N3; ++k)
            {
                if( k != 0)
                    std::cout << ", ";
                std::cout << arry[i][j][k]; 
            } 
            std::cout << "]" ;
        }
        std::cout << "]" ; 
    }
    std::cout << "]" ; 
}

#endif //__LT_CPP_ARRAY__