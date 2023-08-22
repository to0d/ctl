#include <lt_help/lt.h>

int main()
{
    using namespace std;

    typedef map<int,string>             map_type;
    typedef pair<int,string>            pair_type;
    typedef map<int,string>::iterator   map_iter;

    map_type  m;

    //insert operation
    m.insert(pair_type(1,"v1"));
    m.insert(make_pair(2,"v2"));
    m.insert(map_type::value_type(3,"v3"));
    m[4] = "v4";
    
    cout << "output: ";
    outputMap(m);
    cout << endl;  
}
