/*
Longest Consecutive Sequence 
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <vector>
#include <iostream>
#include <unordered_map>

/*
only know nlgn solution:
1. sort input
2. use max for keep max length. 
for each item:
  if it - last one ==1, length+1;
  if it- last onw ==0. Do nothing
  else
    update max and reset length;

need to handle last case

TODO: figure out how to do it in O(n)
*/


//this solution is O(nlog(n)), for O(n) I think it should use hashtable
//TODO: how to do with hastable? or may be a queue?
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        
        int max=1;
        int length=1;
        int last=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last==1){ //consecutive
                length++;
            }else if(nums[i]-last==0){  //do nothing
                
            }else{ //non consecutive
                max=(max>length)?max:length;
                length=1;
            }
            last =nums[i];
        }
        
        //handle last case
        max=(max>length)?max:length;
                
        return max;
    }
};


int main(){

  return 0;
}