#include <lt_help/lt.h>

int main(void)
{
    
    string s1   = "string1";
    string s2[] = {"s1","s2"};
    string* ps3 = new string[2];
    ps3[0] = "s41";    
    ps3[1] = "s42";
    
    cout << "output: ";
    cout << "s1="    << s1    << ", ";
    cout << "s2[0]=" << s2[0] << " " << s2[1]    << ", ";
    cout << "*ps3="  << *ps3  << " " << *(ps3+1) << endl;

    return 0;
}