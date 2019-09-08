/*
Valid Palindrome

 Description
 Notes
 Testcase
 Judge
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 Notice

Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Have you met this question in a real interview? Yes
Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<int> tmp;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                tmp.push_back(s[i]);
            }
        }
        
        int i = 0;
        int j = tmp.size()-1;
        
        while(i<j){
            if(tmp[i]!=tmp[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};