/*
Length of Last Word

36% Accepted
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Have you met this question in a real interview? Yes
Example
Given s = "Hello World", return 5.

Note
A word is defined as a character sequence consists of non-space characters only.
*/


#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
lintcode testcase didn't include last char is space one, suck like "a   "!!
so we just travesal the array, find last space index, then do math
return last's char index - last space index
*/ 
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        if(s.empty()) return 0;
        int IndexSpace=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                IndexSpace=i;
        }
        
        return s.size()-1-IndexSpace;
    }
};




int main(){

	return 0;
}