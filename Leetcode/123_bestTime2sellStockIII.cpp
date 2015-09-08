/*
Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int maxProfit_TLE(vector<int> &prices) {
     	int length=prices.size();
        if(length==0) return 0;
        int maxProfit=0;
        //int minStartIndex=0;
        int intial_end=0;
        int *end2=&intial_end;    
        for(int i=0;i<length;i++){
            int profit=findMaxProfit(prices,0,i,end2)+findMaxProfit(prices,i+1,length-1,end2);
            //cout<<findMaxProfit(prices,0,i)<<" "<<findMaxProfit(prices,i+1,length-1)<<" "<<i<<endl;
            if(profit>maxProfit)
                maxProfit=profit;
        }

        return maxProfit;
    }

    int findMaxProfit(vector<int> &prices,int start, int end, int* end2){
        if(start<end)
            if(start!=0){    
                if(start<*end2)
                    return prices[*end2]-prices[start];
                if(start>*end2){
                    *end2=findbigIndex(prices,start,end);
                    return prices[*end2]-prices[start];
                }
            }else 
                return prices[end]-prices[start];
        else
            return 0;
    }

    int findbigIndex(vector<int> prices, int start, int end){
        int maxNUM=prices[start];
        int maxIndex=0;
        for(int i=start;i<=end;i++){
            if(prices[i]>maxNUM){
                maxNUM=prices[i];
                maxIndex=i;
            }
        }

        return maxIndex;
    }

};
*/

/*
这里我们需要两个递推公式来分别更新两个变量local和global，
我们其实可以求至少k次交易的最大利润。我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易
在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，
此为全局最优。它们的递推式为：
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])，
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值，
而全局最优比较局部最优和前一天的全局最优。

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        return maxValue(prices, 2);  
    }
    
    int maxValue(vector<int> prices, int k) { 
        int len = prices.size();  
        if(len == 0) {  
            return 0;  
        }  
        //vector<vector<int> > local(len,vector<int>(k+1,0));   // = new int[len][k+1];      
        //vector<vector<int> > global(len,vector<int>(k+1,0));  // global[i][j]: max profit across i days, j transactions  
        
        int local[len][k+1]={0};
        int global[len][k+1]={0};
        
        for (int i = 0; i < len; i++)
            for (int j = 0; j < k+1; j++){
                local[i][j] = 0;
                global[i][j]=0;
            }
        
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

};

int main(){
	vector<int> prices={1,2,4,2,5,7,2,4,9,0};
	Solution s;
	cout<<s.maxProfit(prices)<<endl;

	return 0;
}