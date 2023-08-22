#include <lt_help/lt.h>

static void swap(vector<int>& nums, int a, int b) {
    int t   = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void p2InsertSort(vector<int>& nums) {
    int size = nums.size(), high = 0;
    vector<int> next(size, 0);
    next[0] = -1; 
    for(int i = 1; i < size; ++i)
    {   int last, pos;
        if( nums[i] < nums[0])
        {   last = 0;
            pos = next[0];            
        }
        else
        {   last = -1;
            pos = high;
        }        

        while(pos >= 0 && nums[i] < nums[pos])
        {   last = pos;
            pos = next[pos];
        }
        
        if( last < 0 )
        {   next[i] = high;
            high = i;
        }
        else
        {   next[last] = i;
            next[i] = pos;            
        }
    }

    //重排静态链表
    int pos = high;
    for(int i = size -1 ;i >= 0; --i)
    {   int next_pos = next[pos];        
        if( pos != i ) 
        {   int pos2 = pos;
            while( pos2 >= 0 && next[pos2] != i) 
                pos2 = next[pos2];
            swap(nums, pos, i);
            next[pos] = next[i];
            
            if( pos2 >=0 )  
                next[pos2] = pos;
        }
        pos = next_pos;
    }
}


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    p2InsertSort(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}


int main( void )
{
    test({8,9,3,2,6,5,7,1,4});
    return 0;
}

