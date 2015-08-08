/*
Median

Given a unsorted array with integers, find the median of it. 

A median is the middle number of the array after it is sorted. 

If there are even numbers in the array, return the N/2-th number after sorted.

Have you met this question in a real interview? Yes
Example
Given [4, 5, 1, 2, 3], return 3

Given [7, 9, 4, 5], return 5

Challenge
O(n) time.
*/


/*
I sort array and return middle one O(nlg(n)).
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

class Solution_sort {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        if(nums.size()%2==0) return nums[nums.size()/2-1];
        else
            return nums[nums.size()/2];
    }
};

//like quicksort, try to read it
class Solution {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public: 
    int median(vector<int>& nums) {
        // write your code here
        int len  = nums.size();
        if (len%2 == 0) return search(nums, len/2, 0, len-1);
        else return search(nums, len/2+1, 0, len-1);
    }
    
    int search(vector<int>& nums, int k, int start, int end) {
        int l=start, r=end;
        int pivot = r;
        while (true) {
            while (nums[l] < nums[pivot] && l<r) {
                l++;
            }
            while (nums[r] >= nums[pivot] && l<r) {
                r--;
            }
            if (l == r) break;
            swap(nums, l, r);
        }
        swap(nums, l, end);
        if (k == l+1) return nums[l];
        else if (k > l+1) return search(nums, k, l+1, end);
        else return search(nums, k, start, l-1);
    }
    
    void swap(vector<int>& nums, int l, int r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
};


int main(){


	return 0;
}