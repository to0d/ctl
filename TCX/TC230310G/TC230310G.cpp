#include <lt_help/lt.h>

int main(void)
{
    std::string str = "str";
    std::vector<std::string> v;
    cout<< "input: str=" << str << ", v=";
    outputVector(v);

    v.push_back(std::move(str));
    
    cout<< "; output: str=" << str << ", v=";
    outputVector(v);

    cout << endl; 
}
