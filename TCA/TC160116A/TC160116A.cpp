#include <lt_help/lt.h>

// Question :  common sub-string    
//   
//     Please implement a function to find the longest 
//          common sub–string of two given string. 
//     For example:
//        string a: abcdefg12345
//        string b: cdef234
//        longest common sub-string:cdef
// 
// 
// URL http://codepad.org/WB3SVKju 
//         Output:
//         A=abcdefg12345,B=xxxx,C=null
//         A=abcdefg12345,B=xxcdef234,C=cdef
//         A=xxcdef234,B=abcdefg12345,C=cdef

string findCommonString(string s, string t) {
     int s_size = s.size(), t_size = t.size();
     int max_pos = -1, max_len = 0;
     
     for(int i = 0; i < (s_size - max_len); ++i)
        for(int j=0; j < (t_size - max_len); ++j)
        {   int k = 0;
            while( k<(s_size - max_len) && k<(t_size - max_len) && s[i+k] == t[j+k] )
                ++k;
            if( k > max_len)
            {   max_len = k;
                max_pos = i;
            }
        }

    return s.substr(max_pos, max_len);
}

void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t;
    string r = findCommonString(s, t);
    cout << "; output: " << r << ";" << endl;
}


int main( void )
{
    test("xxcdef234","abcdefg12345"); 
    return 0;
}

