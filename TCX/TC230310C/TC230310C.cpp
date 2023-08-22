#include <lt_help/lt.h>

using namespace std;
 
int main(void)
{
    std::vector<int> some_list;
    int total = 0;
    for (int i = 0; i < 5; ++i) 
        some_list.push_back(i);
    std::for_each( begin(some_list), end(some_list), [&total](int x) { total += x; });
    cout << "output: total=" << total << endl;
}
