/*
344. Reverse String   My Submissions QuestionEditorial Solution
Total Accepted: 5861 Total Submissions: 9839 Difficulty: Easy
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
 
/*
two pointer swap
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            char tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
            i++;
            j--;
        }
        
        return s;
    }
};

int main(){

    return 0;
}