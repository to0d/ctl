#include <lt_help/lt.h>

/*

如何能够在 8×8 的国际象棋棋盘上放置八个皇后，使得任何一个皇后
都无法直接吃掉其他的皇后？为了达到此目的，任两个皇后都不能处于
同一条横行、纵行或斜线上

*/
using namespace std;

//#define OUTPUT

#ifdef OUTPUT
static int output_index = 0;
#endif

int _findQueue(int* y, int x, int n)
{
	if( x == n )
	{
#ifdef OUTPUT
		printf("%03d: ",++output_index);
		for( int i = 0; i < n; ++i)
            printf(" %d",y[i]);

		printf("\n");
#endif
		return 1;
	}

    int count = 0 ; 
    for( int v = 0; v < n; ++v)
	{
		bool confic = false;
        for(int x1 = 0; x1 < x && !confic; ++x1)
	    {
	    	int y1 = y[x1];
	    	if( y1 == v)
	    	{
				confic = true;
				break;
			}

	    	int dx = abs(x-x1);
	    	int dy = abs(v-y1);
	    	if( dx == dy)
	    	{
				confic = true;
				break;
			}
	    }

		if(confic)
			continue;
		
		y[x] = v;
        
		count += _findQueue(y,x+1,n);		
	}
    
    return count;
}

int findQueue(int n)
{
#ifdef OUTPUT
    output_index = 0;
#endif

    int* y = new int [n];
    
    int count = _findQueue(y,0,n);
    
    delete [] y;
    
    return count;
}

void test(int n)
{
    int out = findQueue(n);
    cout << "input: " << n << "; output: " << out << endl;
}

int main(void)
{
    test(8);
    return 0;
}

