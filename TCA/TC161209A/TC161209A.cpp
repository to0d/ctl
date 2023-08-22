#include <lt_help/lt.h>

static void swap(vector<int>& nums, int a, int b) {
    int t   = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void _heapAdjust(vector<int>& nums, int s, int m) {
    if( ( 2*s + 1) > m )
        return; 
    
    int guard = nums[s], count = 0;
    for(int j = 2*s + 1; j <= m ; j = 2*j+1)
    {   if( j < m && nums[j] < nums[j+1] ) 
            ++j;
        if( guard >= nums[j] )
            break;
        nums[s] = nums[j];
        ++count;
        s = j;
    }

    if( count > 0 ) 
        nums[s] = guard;
}

void heapSort(vector<int>& nums) {
    int size = nums.size(); 
    for (int h = size/2; h >= 0; --h)
        _heapAdjust(nums, h, size-1);
    
    for(int h = size - 1; h > 0 ; --h)
    {   swap(nums, 0, h);
        _heapAdjust(nums, 0, h-1); 
    }
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    heapSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

