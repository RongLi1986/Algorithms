/*
Wood Cut
Given n pieces of wood with length L[i] (integer array). 
Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. 
What is the longest length you can get from the n pieces of wood? 
Given L & k, return the maximum length of the small pieces.
*/

/*
O(n*len)  or O(lgn *len )
*/

#include <iostream>
using namespace std;

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int maxLen = 0;
        int minCut = 0;
        for(int i = 0; i < L.size();i++){
            if(L[i]>maxLen){
                maxLen = L[i]; 
            }
        }
        
        /*
        //O(n)  
        for(int i=maxLen;i>0;i--){
            minCut = countCut(L,i);
            if(minCut>=k){
                return i;
            }
        }
        */

        //lg(n) implement
        int left = 1;
        int right = maxLen;

        while(left+1<right){
            int mid = left + (right - left)/2; //overflow
            minCut = countCut(L,len);
            if(minCut>=k){
                left = mid;
            }else{
                right = mid;
            }
        }


        if (count(L, right) >= k) {
            return right;
        }        

        if (count(L, left) >= k) {
            return left;
        }


        //all result smaller than k or L is empty
        return 0;
    }   
    
    int countCut(vector<int> &L, int len){
        int sum=0;
        
        for(int i=0;i<L.size();i++){
            sum+=L[i]/len;
        }
        
        return sum;
    }
};

int main(){

	return 0;
}