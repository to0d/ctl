#include <lt_help/lt.h>

void shellInsertSort(vector<int>& nums) {
    static int ddnums [4] = {7,5,3,1};
    int size = nums.size(); 
    for(int dd : ddnums)
    {   for(int i = 0; i < dd; ++i)
        {   for(int j = dd; j < size; j += dd)
            {   if( nums[j] < nums[j - dd] )
                {   int guard = nums[j], m = j - dd;
                    for(; m >= 0 && guard < nums[m];  m -= dd)
                        nums[m+dd] = nums[m];
                    nums[m+dd] = guard;
                }
            }
        }
    } 
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    shellInsertSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

