/*
mplement Queue using Stacks
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

/*
SAME AS IMPLEMENT STACK by using QUEUE
*/


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <cassert>

using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(stack1.empty()) return;
        //put items in stack1 to stack2
        while(stack1.size()>1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.pop();

        //push them back
        while(stack2.size()>0){
            stack1.push(stack2.top());
            stack2.pop();
        }

    }

    // Get the front element.
    int peek(void) {
        int out;
        if(stack1.empty()) return 0;
        //put items in queue1 to queue2
        while(stack1.size()>1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        out=stack1.top();
        stack2.push(stack1.top());
        stack1.pop();

        while(stack2.size()>0){
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        return out;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty();
    }
};



int main(){
    
    return 0;
}