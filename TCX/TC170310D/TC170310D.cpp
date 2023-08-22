#include <lt_help/lt.h>

int main()
{
    vector<int> v;
    for(int i=0;i<10;++i) 
        v.push_back(i);
    
    cout << "input: ";
    outputVector(v);

    vector<int>::iterator it = v.begin();
    while( it != v.end())
    {   if(*it % 2 == 0)
            it = v.erase(it);
        else
            ++it;
    }
    
    cout << "; output: ";
    outputVector(v);
    cout << endl; 
}
