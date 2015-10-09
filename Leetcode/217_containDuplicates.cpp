/*
Contains Duplicate 
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
*/

/*
O(n) by using hashmap save each number
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
private:
    unordered_map<int,int> myMap;
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        for(int i=0;i<nums.size();i++){
            //unordered_map<int,int>::iterator itr=myMap
            if(myMap.find(nums[i])==myMap.end()){
                myMap[nums[i]]=1;
            }else{
                return true;   
            }
        }
        
        return false;
    }
};

int main(){
	Solution s;

	return 0;
}








