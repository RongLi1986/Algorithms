/*
Implement Stack using Queues
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only 
push to back, 
peek/pop from front, 
size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

*/

/*
use two queue.
copy all items from one queue to another for top() and pop(),return item value
or pop() the last one.
similar question: use two stack to implement a queue.
*/


#include <iostream>
#include <deque>
#include <cassert>

using namespace std;

class Stack_other {
private:
    queue<int> que1;
    queue<int> que2;
public:
    // Push element x onto stack.
    void push(int x) {
        que1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(que1.size()!=1){
            int tmp=que1.front();
            que1.pop();
            que2.push(tmp);
        }
        que1.pop();
        while(que2.size()!=0){
            int tmp=que2.front();
            que2.pop();
            que1.push(tmp);
        }
        return;
    }

    // Get the top element.
    int top() {
        int res;
        while(que1.size()!=0){
            if(que1.size()==1)
                res=que1.front();
            int tmp=que1.front();
            que1.pop();
            que2.push(tmp);
        }
        
        while(que2.size()!=0){
            int tmp=que2.front();
            que2.pop();
            que1.push(tmp);
        }
        
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.size()==0 && que2.size()==0;
    }
};

class Stack {
private:
	deque<int> queue1;
	deque<int> queue2;
	int flag;
public:
	Stack(){
		int flag=1; //first we use queue1
	}
    // Push element x onto stack.
    void push(int x) {
        if(flag==1)
        	queue1.push_back(x);
        else
        	queue2.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(flag==1){
        	if(queue1.empty()) return;
        	//put items in queue1 to queue2
        	while(queue1.size()>1){
        		queue2.push_back(queue1.front());
        		queue1.pop_front();
        	}
        	queue1.pop_front();
        	assert(queue1.empty());
        	flag=2;
        }else{
        	if(queue2.empty()) return;
        	//put items in queue2 to queue1
        	while(queue2.size()>1){
        		queue1.push_back(queue2.front());
        		queue2.pop_front();
        	}
        	queue2.pop_front();
        	assert(queue2.empty());
    		flag=1;
        }
    }

    // Get the top element.
    int top() {

    	int out;
        if(flag==1){
        	if(queue1.empty()) return 0;
        	//put items in queue1 to queue2
        	while(queue1.size()>1){
        		queue2.push_back(queue1.front());
        		queue1.pop_front();
        	}
        	out=queue1.front();
        	queue2.push_back(queue1.front());
        	queue1.pop_front();
        	assert(queue1.empty());
        	flag=2;
        }else{
        	if(queue2.empty()) return 0;
        	//put items in queue2 to queue1
        	while(queue2.size()>1){
        		queue1.push_back(queue2.front());
        		queue2.pop_front();
        	}
        	out=queue2.front();
        	queue1.push_back(queue2.front());
        	queue2.pop_front();
        	assert(queue2.empty());
        	flag=1;
        }

        return out;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty()&&queue2.empty();
    }
};

int main(){
	Stack s;
	cout<<s.empty()<<endl;
	//s.push(1);
	//s.push(2);
	//s.push(3);
	cout<<s.top()<<endl;

	s.pop();
	s.pop();
	cout<<s.top()<<endl;

	return 0;
}