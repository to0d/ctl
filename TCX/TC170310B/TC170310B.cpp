#include <lt_help/lt.h>

int main()
{
    vector<int> v;
    for(int i =0; i< 100; i++)
        v.push_back(i);
    
    //3) erase one
    v.pop_back();
    v.reserve(1000000);
    
    cout << "output: before swap, size=" << v.size() << ", capacity=" << v.capacity();
    
    vector<int> (v).swap(v);  //4) use Shrink to fit method

    cout << "; after swap, size=" << v.size() << ", capacity=" << v.capacity() << endl;
}
