/*
First Missing Positive Total Accepted: 35231 Total Submissions: 153031 My Submissions Question Solution 
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


/*O(n) 
two travese array, first time we put each item into hashmap
and save max number.
second time we match (1~max number) number with hm,if not find
in hashmap, return it
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//my way
class Solution {
private:
  unordered_map<int,int> myMap;
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int maxNum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxNum) maxNum=nums[i];
            myMap[nums[i]]=1;
        }

        //ignore negtive number
        for(int i=0;i<=maxNum;i++){
            if(myMap.find(i+1)==myMap.end()){
                return i+1;
            }
        }
        return maxNum+1;
    }
};


//olg(n) sort item and find index
class Solution_1 {  
public:  
    int firstMissingPositive(int A[], int n) {  
        sort(A, A+n);  
        int res = 0;  
        int i = 0;  
        while (i<n && A[i]<=0) i++; //kill negative number  
        for (; i < n; i++)  
        {  
            if (i>0 && A[i] == A[i-1]) continue;  
            if (A[i] - res != 1) return res+1;  
            else res = A[i];  
        }  
        return res+1;  
    }

    //O(n)
    int firstMissingPositive2(int A[], int n) {  
        for (int i=0; i<n; i++)  
        {  
            if (A[i] > 0 && A[i] < n)  
            {  
                //if (A[i]-1 != i && A[A[i]-1] != A[i])不用那么多条件就可以了。  
                //因为只要是已经到位了的元素即：A[i]-1==i了，那么判断如果有重复元素  
                //两个位置交换就最好考虑好两个位置出现的可能情况。考虑问题全面，两个条件都考虑好。  
                //update:增加i!=A[i]表示i位置没到位，A[A[i]-1] != A[i]表示A[i]-1位置没到位，两个位置都判断也很好的。  
                if (A[A[i]-1] != A[i])  
                {  
                    swap(A[A[i]-1], A[i]);  
                    i--;  
                }  
            }  
        }  
  
        for (int j=0; j<n; ++j)  
            if (A[j]-1 != j)  
                return j+1;  
  
        return n+1;   
    }    
};  

int main(){
  vector<int> nums={2};

  Solution s;
  cout<<s.firstMissingPositive(nums)<<endl;

  return 0;
}