#include <lt_help/lt.h>

int main(void)
{    
    int a1 [] = {1,2};
    int a2 [][3] = {{1,2},{3,4,5}};
    // int a2 [][] = {{1,2},{3,4,5}};       //��������˵�һ�±�������±��Զ��ƶ�
    int a3 [2][3][2] = {{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}};

    std::cout <<"a1: ";   outputArray(a1); std::cout << endl;
    std::cout <<"a2: ";   outputArray(a2); std::cout << endl;
    std::cout <<"a3: ";   outputArray(a3); std::cout << endl;

    char s1[] = {'a','b','c'};
    char s2[] = "abc";                      //�������ַ������ʽ��ϵͳ�Զ���'\0'
    char s3[][4] = {"abc","ef","x"};
    char s4[][2][2] = {"a","b","c","d"};

    std::cout <<"s1: ";   outputArray(s1);  std::cout << endl;
    std::cout <<"s2: ";   outputArray(s2);  std::cout << endl;
    std::cout <<"s3: ";   outputArray(s3);  std::cout << endl;
    std::cout <<"s4: ";   outputArray(s4);  std::cout << endl;
    
    std::cout << "output: done!" << endl;
    
    return 0;
}
