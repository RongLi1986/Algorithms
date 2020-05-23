# 75. Sort Colors

## Question link
(https://leetcode.com/problems/sort-colors/description/)

## Question Description

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?


## 解题思路
O(n) sort

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int countOne = 0;
        int countZero = 0;

        while(i < nums.size()){
            if(nums[i] == 0){
                countZero++;
            }else if(nums[i] == 1){
                countOne++;
            }
            i++;
        }

        i = 0;
        while(i < nums.size()){
            if(countZero != 0){
                nums[i] = 0;
                countZero--;
            }else if(countOne != 0){
                nums[i] = 1;
                countOne--;
            }else{
                nums[i] = 2;
            }
            i++;
        }
    }
};

class Solution {
  public:
  /*
  Dutch National Flag problem solution.
  */
  void sortColors(vector<int>& nums) {
    // for all idx < p0 : nums[idx < p0] = 0
    // curr is an index of element under consideration
    int p0 = 0, curr = 0;
    // for all idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};
```