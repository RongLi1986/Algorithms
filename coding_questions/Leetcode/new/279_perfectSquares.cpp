/*
279. Perfect Squares My Submissions Question
Total Accepted: 20249 Total Submissions: 67122 Difficulty: Medium
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.*/


/*
DP
*/


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;    

int numSquares(int n) {
    //corner case
    if(n<=3)
        return n;
        
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    
    for(int i=1;i<n+1;i++){
        
        int j=1;
        while(1){

            int tmp=j*j;
            if(tmp>i) break;
            if(dp[i-tmp]==INT_MAX) continue;
            dp[i]=min(dp[i-tmp]+1,dp[i]);
            //cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
            j++;
        }
    }

    return dp[n];// == INT_MAX ? -1 : dp[amount];
}


int main(){
    cout<<numSquares(16)<<endl;
    //cout<<numSquares(10)<<endl;
    //cout<<numSquares(12)<<endl;
    //cout<<numSquares(13)<<endl;

    return 1;
}