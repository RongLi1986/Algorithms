/*
Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example
Given s = "aab", return:

[
  ["aa","b"],
  ["a","a","b"]
]
*/


/*
backtracking + DFS
*/

class Solution {
private:
     vector<vector<string>> res;
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<string> tmp;
        partitionRes(s, 0, tmp);
        
        return res;
    }
    
    void partitionRes(string s, int start, vector<string> tmp){
        if(start>=s.size()){
            if(!tmp.empty())
                res.push_back(tmp);
            return;   
        }
        
        for(int i = start;i < s.size(); i++){
            string subStr = s.substr(start, i-start+1);
            //cout<<subStr<<endl;
            if(isPalindrone(subStr)){
                tmp.push_back(subStr);
                partitionRes(s, i+1, tmp);
                tmp.pop_back();
            }
        }
        
        return;
    }
    
    bool isPalindrone(string s){
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]==s[j]){
                
            }else{
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};