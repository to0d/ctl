#include <lt_help/lt.h>

int main()
{
    vector<int> v;
    
    //2) push_back
    for(int i =0; i< 3; i++)
        v.push_back(i);
   
    cout << "initialize: " << endl;
    cout << "vector : size=" << v.size() << ", content=";
    copy(v.begin(),v.end(),ostream_iterator<int>(cout,","));
    cout << endl;

    //3) out_of_range : 
    // cout << "=> v[3] not exception: " << v[3] <<" : ";    
    // cout << "pass" << "\n" << endl; 
    
    try {
        cout << "output: v.at(3) exception: out_of_range: ";
        cout << v.at(3);
    }
    catch (const out_of_range& oor) {
        //cerr << "Out of Range error: " << oor.what() << '\n';
        cout << "pass" << endl; 
    }   

    return 0;
}
