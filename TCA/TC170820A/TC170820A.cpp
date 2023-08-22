#include <lt_help/lt.h>

using namespace std;

int calculate(int m, int n, int x, int y)
{
#define min(x,y) (x)<(y)?(x):(y)

    int z, s, val;
    
    int x2 = n - x - 1;
    int y2 = m - y - 1;
    int dx = min(x2,x);
    int dy = min(y2,y);
    
    z = min(dx,dy);
    
    if( z > 0 )
        s = 2*(m+n)*z - 4*z*z;
    else
        s = 0;
    
    // up layer
    if( z == y || z == x2 )
        val = s + x + y - 2*z ;
    else
        val = s - x - y + 2*(m+n-2)-6*z;

    return val;
}

void printSpiralMatrix(int m, int n, int s)
{
    int x, y;
    for(y = 0; y < m; ++y)
    {   for(x = 0; x < n; ++x)
            printf("%3d ", calculate(m,n,x,y)+s);  
        printf("\n");
    }        
} 

int main( void )
{
    printSpiralMatrix(11,7,1);
    cout << "output: done" << endl;
    return 0;
}

