#include <lt_help/lt.h>

int main( void )
{ 

    /* *************************************************************** */
    /*  01) copy to ostream_iterator                                   */
    /* *************************************************************** */
    {
            
        // required header files:
        // - ostream_iterator      #include <iterator> 
        // - copy                  #include <algorithm>          
        
        vector<int> numbers = {1, 2, 3};
        
        std::cout << "output: ";
        std::copy( numbers.begin(), numbers.end(), ostream_iterator<int>(cout, ","));        
        cout << endl;
    }
    
    return 0;
}