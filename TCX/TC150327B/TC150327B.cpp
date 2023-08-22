#include <lt_help/lt.h>

int main(void)
{   
   const size_t array_count = 3;   
   std::array<std::string, array_count> a = {"abc","edf","ght"};
   
   std::cout << "output: ";
   outputArray(a);
   cout << endl;
   return 0;
}

