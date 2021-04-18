# 15. 3 Sum

## Question link
(https://leetcode.com/problems/3sum/description/)

## Question Description
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

## 解题思路


```c++
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > out;
        sort(num.begin(), num.end());
        int size = num.size();
        
        for(int i = 0;i < size;i++){
            if(i == 0 || num[i] != num[i - 1]){
                _twoSum(num, num[i], i, out);
            }
        }
        
        return out;
    }

    // hashmap way  -- TLE in current leeetcode
    void _twoSum(vector<int> &numbers, int target, int start, vector<vector<int> > &out){
        unordered_map<int,int> m;  //<key, value>: keep value and index
        int findValue;

        for(int i = start + 1;i < numbers.size(); i++){
            findValue = -1 * (target + numbers[i]);   
            if(m.find(findValue) == m.end()){  //not find 
                if(m.find(numbers[i]) == m.end()){   //avoid duplicate
                    m[numbers[i]] = 1;                 //put in hashmap
                }
            }else{
                if(m[findValue] != -1){
                    out.push_back({target, findValue, numbers[i]});
                    m[findValue] = -1;
                }                       
            }
        }
    }

    // two pointer
    void _twoSum(vector<int> &numbers, int target, int start, vector<vector<int> > &out){
        int left = start + 1;
        int right = numbers.size() - 1;
        
        while(left < right){
            if(numbers[left] + numbers[right] + target == 0){
                out.push_back({target, numbers[left], numbers[right]});
                while(left < right && numbers[left] == numbers[left + 1]) left++;
                left++;
                while(left < right && numbers[right] == numbers[right - 1]) right--;
                right--;
            }else if(numbers[left] + numbers[right] + target < 0){
                left++;
            }else{
                right--;
            }
        }
    }
};
```