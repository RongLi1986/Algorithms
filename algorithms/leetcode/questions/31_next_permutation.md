# 31 Next Permutation

## Question link
(https://leetcode.com/problems/next-permutation/description/)

## Question Description

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

## 解题思路

```c++
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int changeIndex = -1;
        
        for(int i = size - 1; i > 0; i--){
            if(num[i] > num[i-1]){
                changeIndex = i-1;
                for(int j = size - 1; j > changeIndex; j--){
                	if(num[j] > num[changeIndex]){
                		swap(num, j, changeIndex);
                		reverse(num.begin() + changeIndex + 1, num.end());
                		return;
                	}
                }
            }
        }
        
        if(changeIndex == -1)
            reverse(num.begin(),num.end());
       
    }
    
    void swap(vector<int> &num, int origIndex, int changeIndex){
        int tmp = num[changeIndex];
        num[changeIndex] = num[origIndex];
        num[origIndex] = tmp;
    }
};
```