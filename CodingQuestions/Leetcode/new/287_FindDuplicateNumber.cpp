/*
287. Find the Duplicate Number My Submissions Question
Total Accepted: 16182 Total Submissions: 44024 Difficulty: Hard
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
Have you met this question in a real interview? Yes  No
Discuss

*/


/*
how to solve it without using extra space 
anwser: use binary search O(nlgn)
*/


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int low=1;
        int high=n;
        int mid;
        
        //O(nlgn)
        while(low<high){  //lgn
            mid=(low+high)/2;
            int count=0;
            for(int num:nums){  //n
                if(num<=mid) count++;
            }
            if(count>mid) 
                high=mid;
            else 
                low=mid+1; 
        }
        return low;
    }
};



class Solution_old {
private:
    unordered_map<int,int> map;  //key : nums, and value :count 
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.emd()){
                map[nums[i]]=1;
            }else{
                return nums[i];
            }
        }

        //expection handle
        return -1;
    }
};

int main(){



    return 0;
}