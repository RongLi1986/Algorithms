/*
322. Coin Change My Submissions Question
Total Accepted: 3100 Total Submissions: 12276 Difficulty: Medium
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

/*
DP solution



*/


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        if(coins.empty()) return -1;
        if(amount<=0)
            return 0;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<amount+1;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i) break;
                if(dp[i-coins[j]]==INT_MAX) continue;
                dp[i]=min(dp[i-coins[j]]+1,dp[i]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

class Solution_TLE {
private:
    vector<int> res;
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        if(amount<=0)
            return 0;
            
        sort(coins.begin(),coins.end());
        coinChangeRecursive(coins, coins.size()-1,0,amount);
        
        if(res.empty()) return -1;

        sort(res.begin(),res.emd());

        return res[0]; 
    }
    
    void coinChangeRecursive(vector<int>& coins, int start, int count, int amount){
        if(amount==0) {
            res.push_back(count);
            return;
        }
        
        if(amount<0) return;
        
        for(int i=start;i>=0;i--){
            coinChangeRecursive(coins,i,count+1,amount-coins[i]);
            if(!res.empty()) return;
        }

        return;
    }
};

int main(){

    return 0;
}