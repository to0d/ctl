#include <lt_help/lt.h>

int main()
{
    set<int> s;
    for(int i=0;i<6;++i) 
        s.insert(i);

    cout<<"input: "; 
    outputSet(s);

    set<int>::iterator it = s.begin();
    while( it != s.end())
    {
        if(*it % 2 == 0)
             s.erase(it++); // the deleted iterator will be useless, 
                            // use it++ to make a clone one
        else
            ++it;
    }

    cout<<"; output: ";
    outputSet(s);
    cout<< endl; 
}