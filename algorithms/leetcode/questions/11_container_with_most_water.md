# 11 Container With Most Water

## Question link
(https://leetcode.com/problems/container-with-most-water/description/)

## Question Description
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 ![Image](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)


The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49



## 解题思路
we setup two pointers from left and right side, each time we move shorter one to center, caculate and maintain the max the area
until left and right pointer meet together.

```c++
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        int left    = 0;
        int right   = height.size() - 1;
        
        while(left<right){
            maxArea = max(maxArea, min(height[left],height[right])*(right-left)); //why right-left??
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

    	return maxArea;
    }
};
```