#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstdlib>

//#################################################################################
//
//
//
//#################################################################################

using namespace std;

void test_union();
void test_set_bit();
void test_swap_word();
void test_malloc_0();

int  main(void)
{
   test_union();
   test_set_bit();
   test_swap_word();
   test_malloc_0();
   
   cout << "output: done!" << endl;
   
   return 0;
}

union 
{
	unsigned char a;
	unsigned int i;
} u;


void test_union()
{
    std::cout <<"\n==>  test_union: \n\n";
 	
	cout << "TEST 01: " << endl;
	printf("%f\n",5);
	printf("%d\n",5.01);
    cout << endl << endl;

	cout << "TEST 06: " << endl;
	u.i = 0xf1f2f3f4;

	cout << hex << u.i << endl;
	cout << hex << int(u.a) << endl;
    cout << endl << endl;
        
    std::cout <<"-----------------------------------------------\n\n";
}

#define BIT_ON_3 (1<<3)

void test_set_bit()
{
    std::cout <<"\n==>  test_set_bit: set bit on 3 pos \n\n";
 	
    int a = 0x00F1;
	cout << "1st:" << bitset<16>(a) << endl;
	a |= BIT_ON_3;
	cout << "2st:" << bitset<16>(a) <<" set 1 on 3" <<  endl;
	a &=~BIT_ON_3;
	cout << "3st:" << bitset<16>(a) <<" set 0 on 3" <<  endl;
        
    std::cout <<"-----------------------------------------------\n\n";
}

void test_swap_word()
{
    std::cout <<"\n==>  test_swap_word: \n\n";
 
 	int word = 0xabcd;
	cout << "input : " << hex << word << endl;
	   
	word = (( word & 0xFF00 ) >> 8 ) | (( word & 0x00FF ) << 8 ); 
	cout << "output: " << hex << word << endl;

    std::cout <<"-----------------------------------------------\n\n";
}

void test_malloc_0()
{
    std::cout <<"\n==>  test_malloc_0: \n\n";

	char* ptr;
	if( (ptr = (char*) malloc(0)) == NULL)
	{
	   cout << "Got a null pointer by malloc(0) " << endl;
	}
	else
	{
	   cout << "Got a invaild pointer by malloc(0) " << endl;
	}


    std::cout <<"-----------------------------------------------\n\n";
}
