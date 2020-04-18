# 42. Trapping Rain Water

## Question link
(https://leetcode.com/problems/trapping-rain-water/description/)

## Question Description

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 ![Image](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6


## 解题思路
Find maximum height of bar from the left end upto an index i in the array left_max.
Find maximum height of bar from the right end upto an index i in the array right_max.
ans[i] = min(left_max[i], right_max[i]]) - height[i];


```c++
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l(height.size(), 0);
        vector<int> r(height.size(), 0);
        
        int left = 0;
        for(int i = 0;i < height.size(); i++){
            left = (height[i] > left) ? height[i] : left;
            l[i] = left;
        }
        
        int right = 0;
        for(int i = height.size() - 1;i >= 0; i--){
            right = (height[i] > right) ? height[i] : right;
            r[i] = right;
        }
        
        int ret = 0;
        for(int i = 0;i < height.size();i++){
            ret += min(l[i], r[i]) - height[i];
        }
        
        return ret;
    }
};
```