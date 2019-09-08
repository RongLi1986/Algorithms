/*
Singleton is a most widely used design pattern. 
If a class has and only has one instance at every moment, 
we call this design as singleton. For example, for class Mouse (not a animal mouse), 
we should design it in singleton.

You job is to implement a getInstance method for given class, 
return the same instance of this class every time you call this method.

example
A a = A.getInstance();
A b = A.getInstance();
a should equal to b.

If we call getInstance concurrently, can you make sure your code could run correctly?
*/

#include <iostream>

class Solution {
private:
    Solution(){ };
    //Solution(Solution const&);              // Don't Implement
    //void operator=(Solution const&);        // Don't implement
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution* instance; 
        return instance;
    }
    
    Solution(Solution const&)           = delete;
    void operator=(Solution const&)     = delete;
    
    ~Solution(){
    };
};

int main(){

    return 0;
}