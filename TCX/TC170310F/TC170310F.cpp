#include <lt_help/lt.h>

int main()
{
    map<int,int> m;
    for(int i=0;i<4;++i) 
        m[i] = i + 10; 
    
    cout << "input: ";
    outputMap(m);     

    auto it = m.begin();
    while( it != m.end())
    {
        if(it->first % 2 == 0)
            m.erase(it++); // the deleted iterator will be useless, 
                           // use it++ to make a clone one
        else
            ++it;
    }
    
    cout << "; output: ";
    outputMap(m);
    cout << endl; 
                 
}
