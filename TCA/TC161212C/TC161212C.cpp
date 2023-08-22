#include <lt_help/lt.h>

void binarayInsertSort(vector<int>& nums) {
    int size = nums.size(); 
    for(int i = 1; i < size; ++i )
    {   if ( nums[i] < nums[i-1] )
        {   int guard = nums[i], h = i - 1, l = 0;
            while( l <= h )
            {   int m = (h + l)/2;
                if( guard < nums[m])
                    h = m - 1;
                else
                    l = m + 1;
            }
            for(int j = i - 1 ; j >= (h+1); --j)  
                nums[j+1] = nums[j]; 
            nums[h+1] = guard; 
        }       
    }    
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    binarayInsertSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

