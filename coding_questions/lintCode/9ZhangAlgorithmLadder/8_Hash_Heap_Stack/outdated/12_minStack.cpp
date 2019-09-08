/*
Min Stack

Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.

 Notice

min operation will never be called if there is no number in the stack.

Have you met this question in a real interview? Yes
Example
push(1)
pop()   // return 1
push(2)
push(3)
min()   // return 2
push(1)
min()   // return 1
*/


/*
use another stk maintain min number
*/

class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if(minStk.empty() || minStk.top()>= number)
            minStk.push(number);
        
        stk.push(number);
    }

    int pop() {
        // write your code here
        if(stk.top() == minStk.top())
            minStk.pop();
        
        int res=stk.top();
        stk.pop();
        return res;
    }

    int min() {
        // write your code here
        return minStk.top();
    }
};