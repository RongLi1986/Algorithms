/*
Given two strings, find the longest common substring.

Return the length of it.

example:
Given A = "ABCD", B = "CBCE", return 2.
*/

#include <iostream>
using namespace std;

/*
brute force:
O(n^3)

DP solution:
f(i,j) = (A[i]==B[j]) ? 1 + f(i-1,j-1) : 0
O(n^2)
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
     
    //brute force 
    /*
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int maxLen = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i]==B[j]){
                    int count = 0;
                    int k=0;
                    while(i+k<A.size()&&j+k<B.size()){
                        if(A[i+k] == B[j+k]){
                            count++;
                        }else
                            break;
                        k++;
                    }
                    
                    if(count>maxLen)
                        maxLen=count;
                    
                }
            }
        }
        
        return maxLen;
    }
    */
    
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        
        if(A.empty() || B.empty()) 
            return 0;
        
        vector<int> mapA(A.size(), 0);
        vector<vector<int> > map(B.size(), mapA);
        
        for(int i=0;i<map.size();i++){
            if(A[0]==B[i])
                map[i][0]=1;
        }
        
        for(int j=0;j<map[0].size();j++){
            if(A[j]==B[0])
                map[0][j]=1;
        }
        
        for(int i=1;i<map.size();i++){
            for(int j=1;j<map[0].size();j++){
                if(B[i]==A[j]){
                    map[i][j] = 1+ map[i-1][j-1];
                }
            }
        }
        
        int maxLen = 0;
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                //cout<<map[i][j]<<" ";
                if(map[i][j]>maxLen)
                    maxLen=map[i][j];
            }
            //cout<<endl;
        }
        return maxLen;
    }


    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m=A.size();
        int n=B.size();
        
        vector<vector<int> > f(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(A[i-1] == B[j-1]){
                    f[i][j] = f[i-1][j-1]+1;       
                }else{
                    f[i][j] = 0;  
                }
            }
        }
        
        int max=INT_MIN;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(f[i][j]>max)
                    max=f[i][j];
            }
        }
        
        return max;
    }
    
};


int main(){

	return 0;
}