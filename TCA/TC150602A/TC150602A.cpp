#include <lt_help/lt.h>

struct Record
{   int time;
    Record(): time(0) {}
};

int SeqSearch(vector<int>& nums, int target, Record& record) {   
    int size = nums.size();
    for( int i = 0; i< size; ++i )
    {   ++(record.time);
        if( nums[i] == target ) 
            return i;        
    }

    return -1;
}


void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);    
    Record record;
    int pos = SeqSearch(nums, target, record); 
    cout << "; output: pos=" << pos << ", times=" << record.time << ";" << endl;
}

int main(void)
{
    test({1,3,5,7,9,11,13,15,23,25,27}, 25);
    return 0;
}