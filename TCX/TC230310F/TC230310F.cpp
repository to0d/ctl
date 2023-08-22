#include <lt_help/lt.h>

using namespace std;
 
class GFG {
};

int main(void)
{
    static_assert(std::is_arithmetic<int>::value, "only supports arithmetic types");
    cout << "output: GFG=" << is_arithmetic<GFG>::value;
    cout << ", bool="  << is_arithmetic<bool>::value;
    cout << ", long="  << is_arithmetic<long>::value;
    cout << ", short=" << is_arithmetic<short>::value << endl;
}
