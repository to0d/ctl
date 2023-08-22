#include <lt_help/lt.h>

int main()
{
    deque<int> d ;
    for(int i=0;i<6;++i) 
        d.push_back(i);
    
    cout<<"input: "; 
    outputDeque(d);

    deque<int>::iterator it = d.begin();
    while( it != d.end())
    {
        if(*it % 2 == 0)
            it = d.erase(it);
        else
            ++it;
    }
    
    cout<<"; output: ";
    outputDeque(d);
    cout<< endl;   
}