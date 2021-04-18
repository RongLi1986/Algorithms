# 84. Largest Rectangle in Histogram

## Question link
(https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)

## Question Description

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![Image](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

![Image](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10

## 解题思路
stack

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        
        int i=0;
        stack<int> st;
        int res = 0;
        
        while(i < height.size()){
            if(st.empty() || height[i] >= height[st.top()]){
                st.push(i);
                i++;
            }else{
                int index = st.top(); st.pop();
                int len = st.empty() ? (i - 0) : (i - st.top() - 1);
                res = max(res, height[index] * len);
            }
        }
                          
        return res;
    }
};
```