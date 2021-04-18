# 18. 4Sum

## Question link
(https://leetcode.com/problems/4sum/description/)

## Question Description
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

## 解题思路
15 three sum 的延伸

```c++
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > out;
    	sort(num.begin(),num.end());
    	int size=num.size();

    	for(int i=0;i<size-1;i++){
    		if(i == 0 || num[i] > num[i - 1]){
	    		for(int j = i + 1;j<size;j++){
	    			if(j == i+1|| num[j] > num[j - 1]){
	    				_twoSum(num,num[i], num[j], target, j, out);
	    			}
	    		}
    		}
    	}

    	return out;
    }

	void _twoSum(vector<int> &numbers, int a, int b, int target, int start, vector<vector<int> > &out){
        int left = start + 1;
        int right = numbers.size() - 1;
        
        while(left < right){
            if(numbers[left] + numbers[right] + a + b == target){
                out.push_back({a, b, numbers[left], numbers[right]});
                while(left < right && numbers[left] == numbers[left + 1]) left++;
                left++;
                while(left < right && numbers[right] == numbers[right - 1]) right--;
                right--;
            }else if(numbers[left] + numbers[right] + a + b < target){
                left++;
            }else{
                right--;
            }
        }
    }
};
```