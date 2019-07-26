/*
345. Reverse Vowels of a String   My Submissions QuestionEditorial Solution
Total Accepted: 2957 Total Submissions: 8041 Difficulty: Easy
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
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
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        int flagI=0;
        int flagJ=0;
        
        while(i<j){
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||
              s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
                flagI=1;
            }else{
                flagI=0;
                i++;
                if(i>s.size()-1)
                    break;
            }
            
            if(s[j]=='a' || s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u' ||
            s[j]=='A' || s[j]=='E' ||s[j]=='I' ||s[j]=='O' ||s[j]=='U'){
                flagJ=1;
            }else{
                flagJ=0;
                j--;
                if(j<0)
                    break;
            }
            
            if(flagI==1 && flagJ ==1){
                char tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                i++;
                j--;
            }
        }
        
        return s;
    }
};

int main(){

    return 0;
}