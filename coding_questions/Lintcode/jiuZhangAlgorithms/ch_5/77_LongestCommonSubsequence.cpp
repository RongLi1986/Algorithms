/*
Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.

example:
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
For "ABCD" and "EACB", the LCS is "AC", return 2.
*/

#include <iostream>
using namespace std;

/*
state:    f[i][j] means LCS of A[0:i] and B[0:j]

initial:

function: f[i]f[j] = max(max(f[i-1][j], f[i][j-1]), f[i-1][j-1])  //A[i]!=B[j]
                   = max(max(f[i-1][j], f[i][j-1]), f[i-1][j-1]+1) //A[i] == B[j] 
result:   f[A.size()-1][B.size()-1]
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A.empty() || B.empty())
            return 0;
            
        vector<int> mapA(A.size(), 0);
        vector<vector<int> > map(B.size(), mapA);
        
        
        //initial
        if(A[0]==B[0])
            map[0][0]=1;
        
        
        for(int i=1;i<map.size();i++){
            if(A[0] == B[i])
                map[i][0]=1;
            else
                map[i][0]=map[i-1][0];
        }
        
        
        for(int i=1;i<map[0].size();i++){
            if(A[i] == B[0])
                map[0][i] = 1;
            else
                map[0][i]=map[0][i-1];
        }
        
        
        //function
        for(int i=1;i<map.size();i++){
            for(int j=1;j<map[0].size();j++){
                if(B[i]==A[j]){
                    map[i][j] = max(map[i-1][j-1]+1, max(map[i-1][j],map[i][j-1]));
                }else{
                    map[i][j] = max(map[i-1][j-1], max(map[i-1][j],map[i][j-1]));
                }
            }
        }
        
        
        //return
        return map[map.size()-1][map[0].size()-1];
    }
};


int main(){

	return 0;
}