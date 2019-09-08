/*
Palindrome Partitioning II

Given a string s, cut s into some substrings such that every substring is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example
Given s = "aab",

Return 1 since the palindrome partitioning ["aa", "b"] could be produced using 1 cut.
*/

#include <iostream>
using namespace std;

/*
DP solution:


*/

//best solution
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        int n = s.length();
        int f[n];
        bool isPalin[n][n];

        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
            if (i + 1 < n) {
                isPalin[i][i + 1] = (s[i] == s[i + 1]);
            }
        }
        
                
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                isPalin[i][j] = isPalin[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<isPalin[i][j]<<" ";
            }
            cout<<endl;   
        }
        */
        
        f[0] = -1;
        for (int i = 1; i <= n; i++) {
            f[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (isPalin[j][i - 1]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        
        return f[n];
    }
};

//normal one
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        vector<int> map(s.size()+1, 0);
        
        map[0]=1;
        
        for(int i=1;i<map.size();i++)
            for(int j=i-1;j>=0;j--){
                if(map[j]>0){
                    if(isPalindrome(s,j,i-1)){
                        if(map[i]==0){
                            map[i]= map[j]+1;
                        }else{
                            map[i] = min(map[j]+1,map[i]);
                        }        
                    }
                }
            }
            
        return map[map.size()-1]-1-1;
    }
    
    bool isPalindrome(string &s, int start, int end){  
        while(start<end){
            if(s[start]!=s[end]) 
                return false;
            start++;
            end--;
        }
        
        return true;
   }  
};

int main(){

	return 0;
}