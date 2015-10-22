/*
Contains Duplicate II Total Accepted: 1873 Total Submissions: 6680 My Submissions Question Solution 
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_TLE {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<i+k;j++){
                if(j==nums.size())  break;
                if(nums[i]==nums[j])
                    return true;
            }
        }
        
        return false;
    }
};


/*
use hashmap to save each number's index
if number value is same, caculate index diff
small or equal to k, return true
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        for(int i=0;i<nums.size();i++){
            //unordered_map<int,int>::iterator itr=myMap
            if(myMap.find(nums[i])==myMap.end()){
                myMap[nums[i]]=i;
            }else{
                if(i-myMap[nums[i]]<=k)
                    return true;
                else
                    myMap[nums[i]]=i;
            }
        }
        
        return false;
    }
    
    private:
    unordered_map<int,int> myMap;
};
int main(){
	Solution s;

	return 0;
}








