#include <lt_help/lt.h>

int main(void)
{   
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    
    cout<<"input: s="; 
    outputSet(s);
    cout<<", max_size="<< s.max_size() ;
    cout<<", *begin=" <<*s.begin();
    
    /* error: attempt to dereference a past-the-end iterator. */
    /*        but no error found in linux                     */
    // cout<<"end()     :"<<*s.end()        << endl;
    
    s.clear();
    
    cout<<"; output: s=";
    outputSet(s);
    cout<<", max_size="<< s.max_size() ;
    cout<<", *begin=" <<*s.begin();
    cout<< endl;   
   
    /* error: attempt to dereference a past-the-end iterator. */
    /*        but no error found in linux                     */
    // cout<<"bein()    :"<<*s.begin() << endl;  
    // cout<<"end()     :"<<*s.end() << endl;   
}
