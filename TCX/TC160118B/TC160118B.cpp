#include <iostream>

//#################################################################################
//
//
//
//#################################################################################

using namespace std;

void test_create_list();

template<class Ty>
struct Node
{
	typedef Node<Ty> 	this_type;
	typedef this_type*  pointer_type;

	Ty value;
	pointer_type m_pNext;
};


template<class Ty>
class  List
{
	typedef Node<Ty>* 	node_ptr;
public:
	List():pHead(NULL),pTail(NULL),m_nCount(0){}

	int getCount() const { return m_nCount; }
	

private:
	List( const List& );
	List& operator = (const List& );

private:
	node_ptr pHead;
	node_ptr pTail;
	int m_nCount;
};

template<class Ty>
Node<Ty>* initList()
{
	Node<Ty>* pHead = new Node<Ty>();
	pHead->m_pNext = pHead;
	return pHead;
}


//template<class Ty>
//void appendTailList(Node<Ty>* pHead, Ty v)
//{
//	
//}

int  main(void)
{
   test_create_list();
   
   cout << "output: done!" << endl;
   
   return 0;
}



void test_create_list()
{
    cout <<"\n==>  test_create_list: \n\n";
	
	List<int> list;

	Node<int>* pHead = initList<int>();
	if(pHead == NULL)
	{
 	   cout << "Fail to create head node" << endl;
	}
	else
	{
 	   cout << "succ to create head node, addr=" <<(void*)pHead << endl;
	}
        
    cout <<"-----------------------------------------------\n\n";
}
