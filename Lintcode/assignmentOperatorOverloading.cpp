/*
Assignment Operator Overloading (C++ Only)

Implement an assignment operator overloading method.

Make sure that:

The new data can be copied correctly
The old data can be deleted / free correctly.
We can assign like A = B = C
Have you met this question in a real interview? Yes
Example
If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B. If we assign like A = B = C, both A and B should have a copy of data from C.

Challenge
Consider about the safety issue if you can and make sure you released the old data.

Clarification
This problem is for C++ only as Java and Python don't have overloading for assignment operator.
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
keep a hashmap, number value as key and number index as its value
travese array if we cannot find key in hasmap(for now no number can match sum with it), 
insert it.
otherwise, put its index and item's value in hashmap in output array

running time:O(n).
*/ 


class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(this != &object) {

        	//clean old m_pData
            free(this->m_pData);
            this->m_pData = NULL;

            //memcpy new data
            if(object.m_pData != NULL) {
                int sz = strlen(object.m_pData);
                this->m_pData = new char[sz + 1];
                memcpy(this->m_pData, object.m_pData, sz + 1);
            }
        }
        
        return *this;
    }
};



int main(){

	return 0;
}