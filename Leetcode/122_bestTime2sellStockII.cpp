/*
Best Time to Buy and Sell Stock II  
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
hint:
从头到尾扫描prices，如果i比i-1大，那么price[i] – price[i-1]就可以计入最后的收益中。这样扫描一次O(n)就可以获得最大收益了
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
     	int Length=prices.size();
     	if(Length==0) return 0;
     	int maxProfit=0;
     	int startIndex=1;
     	for(int i=1;i<Length;i++){
     		if(prices[i]>prices[i-1]){
     			maxProfit+=prices[i]-prices[i-1];
     		}
     	}   

     	return maxProfit;
    }
};

int main(){
	vector<int> prices={1,2,5,4,6,8};
	Solution s;
	cout<<s.maxProfit(prices)<<endl;

	return 0;
}