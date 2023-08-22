#include <lt_help/lt.h>

int _quick_sort_partition(vector<int>& nums, int low, int high) {
    int guard = nums[low];    
    while ( low < high )
    {   while(low < high && guard < nums[high])
            --high;  
        nums[low] = nums[high];
        while(low < high && nums[low] < guard) 
            ++low;
        nums[high] = nums[low];
    }
    nums[low] = guard; 
    return low;    
}


void _quick_sort(vector<int>& nums, int low, int high) {
    if( low < high)
    {   int m = _quick_sort_partition(nums, low, high);
        _quick_sort(nums, low, m-1);
        _quick_sort(nums, m+1, high);
    }
}

void quickSort(vector<int>& nums) {
    int size = nums.size(); 
    _quick_sort(nums,0, size-1);
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    quickSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

