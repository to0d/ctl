#include <lt_help/lt.h>

static void swap(vector<int>& nums, int a, int b) {
    int t   = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void bubbleSort(vector<int>& nums) {
    int size = nums.size(); 
    for(int i = size - 1; i > 0; --i )
    {   int update = 0;
        for(int j = 0; j < i; ++j )
        {   if( nums[j] > nums[j+1] )
            {   swap(nums, j, j+1);
                update++;
            }
        }
        if( update == 0 )
            break;
    }
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bubbleSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

