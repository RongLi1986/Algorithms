/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/


/*
make two stack, one keep input number, other maintain min number for each
operation
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mStk;   //keep input number
    stack<int> mMinStk; //trace minium number for each input;
    
public:
    void push(int x) {
        mStk.push(x);
        if(mMinStk.empty()){
            mMinStk.push(x);
        }else{
            if(x<=mMinStk.top())
                mMinStk.push(x);
        }
    }

    void pop() {
        if(!mStk.empty()){
            int popNum=mStk.top();
            mStk.pop();
            if(popNum<=mMinStk.top())
                mMinStk.pop();
        }else{
            //exception in here
        }

    }

    int top() {
        return mStk.top();
    }

    int getMin() {
        return mMinStk.top();
    }
};

int main(){
	MinStack ms;

	ms.push(2);
	ms.push(3);
	ms.push(1);
	ms.push(5);

	cout<<ms.top()<<endl;
	cout<<ms.getMin()<<endl;
	ms.pop();
	ms.pop();
	cout<<ms.top()<<endl;
	cout<<ms.getMin()<<endl;

	return 0;
}