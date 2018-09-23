/*
Palindrome Partitioning Total Accepted: 37135 Total Submissions: 140251 My Submissions Question Solution 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
  Show Tags
*/


/*
backtracking:
same as permutation, combination and subsets
scan string, if substring is Palindrome. put this sub string into vector 
and recursive to leftover string
*/

#include <iostream>
#include <vector>

using namespace std;

//this is faster!
class Solution {
private:
    vector<vector<string>> out;
public:
   bool isPalindrome(string &s, int start, int end)  
   {  
        while(start< end)  
        {  
             if(s[start] != s[end])  
             return false;  
             start++; 
             end--;  
        }  
        return true;  
   }  

    vector<vector<string>> partition(string s) {
        if(s.empty()) return out;
        vector<string> tmp;
        partitionRecursive(s,0,tmp);
        return out;
    }

    void partitionRecursive(string &s, int startIndex, vector<string> &tmp){
        if(startIndex==s.size()) {
            out.push_back(tmp);
        }

        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                tmp.push_back(s.substr(startIndex,i-startIndex+1));
                partitionRecursive(s,i+1,tmp);
                tmp.pop_back();
            }
        }

        return;
    }

};


class Solution_old {
private:
    vector<vector<string>> out;
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;

        string sf=stringFilter(s);

        int nLength=sf.size();
        int i=0;
        int j=nLength-1;

        while(i<j){
        	if(sf[i]!=sf[j])
        		return false;
        	i++;
        	j--;
        }

        return true;
    }

    string stringFilter(string s){
    	int nLength=s.size();
    	int i=0;
    	string sc;
    	for(;i<nLength;i++){
    		if(isalpha(s[i])||isdigit(s[i])){
    			s[i] = toupper(s[i]);
    			sc.push_back(s[i]);
    		}
    	}

    	return sc;
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty()) return out;
        vector<string> tmp;
        partitionRecursive(s,0,tmp);
        return out;
    }

    void partitionRecursive(string &s, int startIndex, vector<string> tmp){
        if(startIndex==s.size()) {
            out.push_back(tmp);
            //tmp.clear();
        }

        for(int i=startIndex;i<s.size();i++){
            
            string subString(s,startIndex,i-startIndex+1);
            if(isPalindrome(subString)){
                tmp.push_back(subString);
                partitionRecursive(s,i+1,tmp);
                tmp.pop_back();
            }
        }

        return;
    }

};

int main(){
    vector<vector<string>> out;
    string str="baa";
    Solution s;
    out=s.partition(str);

    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j]<<",";
        }
        cout<<endl;
    }


    return 0;
}

