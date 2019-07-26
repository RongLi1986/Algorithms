/*
Maximum Gap 
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*
sort+scan find max diff
O(nlg(n))

TODO:
radix sort maybe better.
*/



#include <vector>
#include <iostream>
using namespace std;

//using radix sort
class Solution_radixSort {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        //radix sort begin
        // m is the maximal number in nums
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i]>m)
                m = nums[i];
        }
    
        
        
        int exp = 1; // 1, 10, 100, 1000 ...
        int R = 10; // 10 digits
    
        vector<int> aux(nums.size(),0);
        
        while (m / exp > 0) { // Go through all digits from LSB to MSB
            vector<int> count(10,0);
            
            for (int i = 0; i < nums.size(); i++) {
                count[(nums[i] / exp) % 10]++;
            }
            
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
    
            for (int i = nums.size() - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % 10]] = nums[i];
            }
    
            
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = aux[i];
            }
    
            exp *= 10;
        }
    
        
        int delta=0;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>delta)
                delta=nums[i+1]-nums[i];
        }
        
        return delta;
    }
};

// it is nlog(n)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int delta=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>delta)
                delta=nums[i+1]-nums[i];
        }
        
        return delta;
    }
};

int main(){


    return 0;
}