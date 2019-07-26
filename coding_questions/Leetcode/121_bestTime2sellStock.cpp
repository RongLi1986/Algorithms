/*
Best Time to Buy and Sell Stock Total Accepted: 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.
 */

/*
it is DP question: scan prices vector, and update a local profit
if local profit larger than maxProfit, update maxProfit
if loacl profit become negative.....update buyIndex
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIndex=0; //index indicate you should buy
        int profit=0;   //local profit
        int maxProfit=0; //global max profit

        for(int i=1;i<prices.size();i++){
            profit=prices[i]-prices[buyIndex];

            //update maxProfit
            if(profit>maxProfit) 
                maxProfit=profit;
            
            //found smaller price, keep it as buy
            if(profit<0)
                buyIndex=i;
        }
        
        return maxProfit;
    }
};

class Solution_old {
public:
    int maxProfit(vector<int> &prices) {
        int length=prices.size();
        if(length==0) return 0;
        
        int maxProfit=0;
        //int minStartIndex=0;
        int minStartValue=prices[0];
        

        for(int i=1;i<length;i++){
        	int diff=prices[i]-minStartValue;
        	if(diff>maxProfit){
        		maxProfit=diff;
        	}else if(diff<0){
        		minStartValue=prices[i];
        		//minStartIndex=i
        	}
        }

        return maxProfit;
    }
};

int main(){
	vector<int> prices={4,5,6,7,1,2,3,};

	Solution s;
	cout<<s.maxProfit(prices)<<endl;


	return 0;
}