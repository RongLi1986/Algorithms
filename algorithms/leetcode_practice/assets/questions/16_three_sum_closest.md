# 16. 3 Sum Closest

## Question link
(https://leetcode.com/problems/3sum-closest/description/)

## Question Description
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

## 解题思路


```c++
class Solution {
public:
    //use way in 3sum
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int size = num.size();
        int ans = 0;
        int min_delta = INT_MAX;
        
        for(int i = 0;i < size;i++){
            if(i == 0 || num[i] > num[i - 1]){ //avoid duplicate
                if(twoSum_closest(num, target, i, min_delta, ans))
                    return target;
            }
        }
        
        return ans;
    }

    bool twoSum_closest(vector<int> &numbers, int target, int index, int &min_delta, int &out){
        int left = index + 1;
        int right = numbers.size() - 1;

        while(left < right){
            if(numbers[left] + numbers[right] + numbers[index] == target){
                return true;
            }else{
                if(abs(target - numbers[left] - numbers[right] - numbers[index]) <= min_delta){
                    min_delta = abs(target - numbers[left] - numbers[right] - numbers[index]);
                    out = numbers[left] + numbers[right] + numbers[index];
                }
                if(numbers[left] + numbers[right] + numbers[index] < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        
        return false;
    }
};
```