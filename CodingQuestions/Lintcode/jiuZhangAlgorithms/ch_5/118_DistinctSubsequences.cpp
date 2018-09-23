/*
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none) of the characters without disturbing the relative positions of 
the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example
Given S = "rabbbit", T = "rabbit", return 3.
*/

#include <iostream>
using namespace std;

/*
DP solution:
state: f(i,j) is number of Distinct Subsequences of S(0:j) and T(:i)
inital: f(0,j) = f(0,j-1) +1 // T[0] == S[j]
               = f(0,j-1)    // T[0] != S[j]
function : f(i,j) = f(i,j-1); //s[j] != T[i]
                  = f(i-1, j-1) + f(i,j-1) ; //s[j] == T[j]
result: f(T.size()-1, S.size()-1)
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        if(S.empty()) return 0;
        if(T.empty()) return 1;
        
        int sizeS=S.size();
        int sizeT=T.size();
        
        vector<int> tmp(sizeS,0);
        vector<vector<int> > map(sizeT, tmp);
        
        if(S[0]==T[0])
            map[0][0] = 1;
        
        for(int i=1;i<sizeS;i++){
            if(T[0]==S[i]){
                map[0][i] = 1+map[0][i-1];
            }else{
                map[0][i] = map[0][i-1];
            }
        }
        
        for(int i=1;i<sizeT;i++){
            for(int j=1;j<sizeS;j++){
                if(T[i]==S[j]){
                    map[i][j]=map[i][j-1] +map[i-1][j-1];
                }else{
                    map[i][j]=map[i][j-1];
                }
            }
        }
        
        /*
        for(int i=0;i<sizeT;i++){
            for(int j=0;j<sizeS;j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        return map[sizeT-1][sizeS-1];  
    }
};



int main(){

	return 0;
}