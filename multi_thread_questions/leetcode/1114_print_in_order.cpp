/*
1114. Print in Order
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}

The same instance of Foo will be passed to three different threads. 
Thread A will call first(), thread B will call second(), and thread C will call third(). 
Design a mechanism and modify the program to ensure that second() is executed after first(), 
and third() is executed after second().

For example:
Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. 
The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). 
"firstsecondthird" is the correct output.

Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), 
and thread C calls second(). "firstsecondthird" is the correct output.
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Foo {   
    mutex m1, m2;
public:
    Foo() {
        m1.lock(), m2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m1.unlock();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m2.unlock();
    }
};