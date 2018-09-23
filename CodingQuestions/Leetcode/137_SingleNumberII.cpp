/*
Single Number 
Given an array of integers, every element appears thrice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
count each bit number in vector, then for number appears three times, mod 3 will make it to 0;
left value is single one number.

*/
#include <vector>
#include <iostream>
class Solution {
public:
    inline bool isBit1(int num, int index)  {
        num = num >> index;
        return (num & 1);
    }

    int singleNumber(vector<int>& nums) {
        int count=0;
        int res=0;
        for(int i=0;i<32;i++){
            count=0;
            for(int j=0;j<nums.size();j++){
                if(isBit1(nums[j],i))
                    count++;
            }
            res|=count%3<<i;
        }
        
        return res;
    }
};

int main(){

    return;
}