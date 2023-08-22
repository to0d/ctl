#include <lt_help/lt.h>

// Simple Singleton class
// unable to free resource which it hold
class CSingleton1
{
	static CSingleton1* m_pInstance;

public:
	static CSingleton1* getInstance(){
		if( m_pInstance == NULL)
            m_pInstance = new CSingleton1();
		return m_pInstance;
	}
	
	CSingleton1(){
	 	cout<< "CSingleton1::construct" << endl;
	}

	~CSingleton1(){
	 	cout<< "CSingleton1::destruct" << endl;
	}

	int value;
};

CSingleton1* CSingleton1::m_pInstance = NULL;

// use inner static member to free resource which it hold
class CSingleton2
{
	static CSingleton2* m_pInstance;
	class Garbo
	{
	public:
		~Garbo(){
			if(CSingleton2::m_pInstance != NULL)
			{   delete CSingleton2::m_pInstance;
				CSingleton2::m_pInstance = NULL;
			}
		}
	};

	static Garbo garbo;
	
public:
	static CSingleton2* getInstance(){
		if( m_pInstance == NULL)
            m_pInstance = new CSingleton2();
		return m_pInstance;
	}
	
	CSingleton2(){
	 	cout<< "CSingleton2::construct" << endl;
	}

	~CSingleton2(){
	 	cout<< "CSingleton2::destruct" << endl;
	}

	int value;
};

CSingleton2* CSingleton2::m_pInstance = NULL;


int main(void)
{
    CSingleton1::getInstance()->value = 101;
    CSingleton2::getInstance()->value = 102;

    cout << "output: ";
    cout << "CSingleton1=" << CSingleton1::getInstance()->value << ", ";
    cout << "CSingleton2=" << CSingleton2::getInstance()->value << endl;

    return 0;
}


