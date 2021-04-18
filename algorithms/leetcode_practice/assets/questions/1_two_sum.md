# 1. Two Sum

## Question link
(https://leetcode.com/problems/two-sum/description/)

## Question Description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


## 解题思路
iterate array and insert each number in hashtable, check if current number exists in hashtable.

running time:O(N)
space: O(N)

```c++
class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> output;  //output vector
		unordered_map<int,int> myMap;  //<key, value>: keep value and index
		int findValue;

		for(int i=0;i<numbers.size();i++){
			findValue=target-(numbers[i]);   
			if(myMap.find(findValue)==myMap.end()){  //not find 
				myMap[numbers[i]]=i;      		     //put in hashmap
			}else{
				output.push_back(myMap[findValue]+1); //save in output vector
				output.push_back(i+1);								
			}
		}

		return output;
	}
};
```