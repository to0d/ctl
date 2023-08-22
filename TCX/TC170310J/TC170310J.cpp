#include <lt_help/lt.h>

int main()
{
    string s = "abcdefgabc";

    cout << "input: " << s;

    string::iterator it =s.begin();
    while( it != s.end())
    {   if(*it == 'a' || *it == 'b' )
            it = s.erase(it);
        else
            ++it;
    }

    cout << "; output: " << s << endl;
}