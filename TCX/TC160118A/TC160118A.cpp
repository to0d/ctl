#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h> //for sleep

//static std::mutex  m;
static std::recursive_mutex  m;
static int count = 0;

static void foo()
{
	m.lock();
	std::cout << count++ << std::endl;
	m.unlock();
}

int main(void)
{
    std::thread t1(foo); 
    std::thread t2(foo); 
    t1.join();
    t2.join();
    usleep(300);
    
    std::cout << "output: done!" << std::endl;
    return 0;
}