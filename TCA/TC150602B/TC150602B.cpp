#include <lt_help/lt.h>

struct Record
{   int time;
    Record(): time(0) {}
};

int BinSearch(vector<int>& nums, int target, Record& record) {
    int h = nums.size() - 1, l = 0;
    while( l <=  h)
    {   ++(record.time);

        int m = (h+l)/2;    
        if( nums[m] == target) 
            return m;
        if( nums[m] < target )
             l = m + 1;
        else
             h = m - 1;
    }

    return -1;
}

void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);    
    Record record;
    int pos = BinSearch(nums, target, record); 
    cout << "; output: pos=" << pos << ", times=" << record.time << ";" << endl;
}

int main(void)
{
    test({1,3,5,7,9,11,13,15,23,25,27}, 25);
    return 0;
}