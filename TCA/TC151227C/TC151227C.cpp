#include <iostream>
#include <cstdio>
#include <cassert>

// 输入两个整数 n 和 m，从数列 1,2,3 ... n 中任意取几个数，使其和等于m
// 求所有可能组合
//
//  f(m,n) =  {} 					        sum(1..n) < m or n <= 0 or m == 0
//  		  {1,2,...n}			        sum(1..n) == m
//  		  f(m,n-1)				        sum(1..n) > m and m < n
//  		  {f(m-n,n-1), n},{f(m,n-1)}    sum(1..n) > m and m >= n
//  		      	                    

using namespace std;

//#define OUTPUT

class algo_find_01_package
{
public:

	algo_find_01_package(int m,int n)
	{
        this->m = m;
        this->n = n;
        this->index = 0;
        
		psum = new int[n];
		phit = new int[n];
		
		for(int i=0; i<n ;++i)
		{   psum[i] = -1;
			phit[i] = 0;
		}
	}

	int find()
	{
        index = 0 ;
		if( m <= 0 || n <= 0 )
			return 0;
	    
        _find(m,n);
        return index;
	}

	void _find(int _m, int _n)
	{
		if( _n <= 0 || getSum(_n) < _m )
            return;

		if( _m == 0 || getSum(_n) == _m ) 
		{   ++index;
#ifdef OUTPUT
			printf("%03d: ", index);
			int sum = 0;
			for( int i = 1; i <= n; ++i)
			{   if( _m !=0 && i <= _n) 
				{   printf(" %2d",i);
					sum += i;
				}
				else 
				{   int hit = phit[i-1];
					printf(" %2d",hit == 1 ? i : 0);
					sum += ( hit == 1 ? i : 0 );
				}
			}
			printf(" sum=%d\n",sum);
#endif
			return;
		}
		
	    if( _m < _n)
        {   _find(_m,_n-1);
            return;
        }
      
		phit[_n-1] = 1; //choose n
		_find(_m-_n,_n-1); 

		phit[_n-1] = 0; //not choose n
		_find(_m,_n-1);
	}

	int getSum(int x)
	{
		if ( x <= 0)
			return 0;
		int sum = psum[x-1];
		if( sum == -1)
		{   sum = getSum(x-1) + x;
			psum[x-1] = sum;
		}
		return sum;
	}

	~algo_find_01_package()
	{
		delete psum;
		delete phit;
	}

private:
	int index;
	int m;
	int n;
	int *psum;
	int *phit;
};

void test(int m, int n)
{
    cout << "input: m=" << m << ", n=" << n;
    algo_find_01_package a(m, n);
    int out = a.find();
    cout << "; output: " << out << endl;
}

int main(void)
{
    test(10, 10);
    return 0;
}

