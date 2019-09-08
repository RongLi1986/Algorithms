/*
Remove Duplicate Numbers in Array

Given an array of integers, remove the duplicate numbers in it.

You should:
1. Do it in place in the array.
2. Move the unique numbers to the front of the array.
3. Return the total number of the unique numbers.

Notice
You don't need to keep the original order of the integers.

Have you met this question in a real interview? Yes
Example
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.
*/

/*
merge
*/

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        // Write your code here
        int end =nums.size()-1;
        int start = 0;
        while(start<=end){
            int j = start+1;
            while(j<=end){
                if(nums[start]==nums[j]){
                    swap(nums,j,end);
                    end--;
                }else{
                    j++;
                }
            }
            start++;
        }
        
        return end+1;
    }
    
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
        return;
    }
};