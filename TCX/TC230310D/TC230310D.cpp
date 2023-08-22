#include <lt_help/lt.h>

using namespace std;
 
int main(void)
{
    int a1 [] = {1,2,3,4};
    int total = 0;
  
    std::for_each( begin(a1), end(a1), [&total](int x) { total += x; });
    cout << "output: total=" << total << endl;

}
