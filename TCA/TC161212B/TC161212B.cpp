#include <lt_help/lt.h>

static void swap(vector<int>& nums, int a, int b) {
    int t   = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void simpleSelectSort(vector<int>& nums) {
    int size = nums.size();   
    int i, j, k;
    for(int i = 0; i < size - 1 ; ++i )
    {   int k = i;
        for(int j = i + 1; j < size; ++j) 
            if( nums[j] < nums[k] )
                k = j;
        if( k != i ) 
            swap(nums, k, i);
    }
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    simpleSelectSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

