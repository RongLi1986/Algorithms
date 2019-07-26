/*
Best Time to Buy and Sell Stock IV 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
这里我们需要两个递推公式来分别更新两个变量local和global，
我们其实可以求至少k次交易的最大利润。我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易
在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，
此为全局最优。它们的递推式为：
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])，
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值，
而全局最优比较局部最优和前一天的全局最优。

但这道题还有个坑，就是如果k的值远大于prices的天数，比如k是好几百万，而prices的天数就为若干天的话，上面的DP解法就非常的没有效率，
应该直接用Best Time to Buy and Sell Stock II 买股票的最佳时间之二的方法来求解，所以实际上这道题是之前的二和三的综合体

*/

class Solution {
public:
    int maxProfit(int k,vector<int> &prices) {
        if(prices.empty()) return 0;
        if(k>=prices.size()/2) return solveMaxProfit(prices);
   
        return maxValue(prices, k);
    }
    
    int maxValue(vector<int> prices, int k) { 
        int len = prices.size();  
        if(len == 0) {  
            return 0;  
        }  
        vector<vector<int> > local(len,vector<int>(k+1,0));   // = new int[len][k+1];      
        vector<vector<int> > global(len,vector<int>(k+1,0)); 
        //int[][] global = new int[len][k+1];     // global[i][j]: max profit across i days, j transactions  
        for(int i=1; i<len; i++) {  
            int diff = prices[i] - prices[i-1];  
            for(int j=1; j<=k; j++) {  
                int tmp=global[i-1][j-1]+ max(diff,0);
                int tmp2=local[i-1][j]+diff;
                local[i][j] = max(tmp, tmp2);  
                global[i][j] = max(global[i-1][j], local[i][j]);  
            }  
        }
        
        
        return global[len-1][k];  
    }
    
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }


};

int main(){
	vector<int> prices={1,2,4,2,5,7,2,4,9,0};
	Solution s;
	cout<<s.maxProfit(prices)<<endl;

	return 0;
}