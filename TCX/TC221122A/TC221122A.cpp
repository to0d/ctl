#include <lt_help/lt.h>

using namespace std;
 
int main(void)
{
    TreeNode* tree = makeTree("{1,2,3,#,#,#,4}");
    
    std::cout << "output: ";
    outputTree(tree);
    std::cout << endl;
}
