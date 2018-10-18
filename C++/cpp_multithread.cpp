#include <iostream>
#include <thread>
#include <mutex>

//baisc example for thread and mutex lock

//build cmd: g++ cpp_multithread.cpp -std=c++11 -pthread
using namespace std;

std::mutex g_lock;
// A dummy function 
void foo(int Z) 
{ 
	g_lock.lock();
    for (int i = 0; i < Z; i++) { 
        cout << i <<" Thread using function pointer as callable" <<endl; 
    } 
    g_lock.unlock();
} 
  
// A callable object 
class thread_obj { 
public: 
	
    void operator()(int x) 
    { 
    	g_lock.lock();
        for (int i = 0; i < x; i++) 
            cout << i <<" Thread using function object as  callable"<<endl; 
        g_lock.unlock();
    } 
    
}; 
 
int main()
{
    cout << "Threads 1 and 2 and 3 operating independently" << endl; 
  
    // This thread is launched by using  
    // function pointer as callable 
    thread th1(foo, 3); 
  
    // This thread is launched by using 
    // function object as callable 
    thread th2(thread_obj(), 3); 
  
    // Define a Lambda Expression 
    auto f = [](int x) { 
    	g_lock.lock();
        for (int i = 0; i < x; i++) 
            cout << i <<" Thread using lambda expression as callable"<<endl;
        g_lock.unlock(); 
    }; 
  
    // This thread is launched by using  
    // lamda expression as callable 
    thread th3(f, 3); 
  
    // Wait for the threads to finish 
    // Wait for thread t1 to finish 
    th1.join(); 
  
    // Wait for thread t2 to finish 
    th2.join(); 
  
    // Wait for thread t3 to finish 
    th3.join(); 

    return 0;
}