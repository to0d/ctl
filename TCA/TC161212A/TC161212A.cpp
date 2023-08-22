#include <lt_help/lt.h>

void simpleInsertSort(vector<int>& nums) {
    int size = nums.size();    
    for(int i = 1; i < size; ++i )
    {   if (nums[i] < nums[i-1] )
        {   int guard = nums[i], j = i - 1; 
            for( ; j >= 0 && guard < nums[j] ; --j)  
                nums[j+1] = nums[j];
            nums[j+1] = guard; 
        }       
    }    
}

void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    simpleInsertSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}

int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

