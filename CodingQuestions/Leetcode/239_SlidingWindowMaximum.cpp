/*
Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/


/*
sol:how to fastest find a max number from this window?


*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.empty()||k==0) return result;
        deque<int> q;
        deque
        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        result.push_back(nums[q.front()]);

        for(int i=k;i<nums.size();i++){
            while(!q.empty()&&nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            while(!q.empty()&&i-q.front()>k-1){
                q.pop_front();
            }
            q.push_back(i);
            result.push_back(nums[q.front()]);

        }
        
        return result;
    }
};




/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.empty()||k==0) return result;
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[i]>=nums[q.back()]){
            	q.pop_back();
            }
            q.push_back(i);
        }

        result.push_back(nums[q.front()]);

        for(int i=k;i<nums.size();i++){
        	while(!q.empty()&&nums[i]>=nums[q.back()]){
            	q.pop_back();
            }
            while(!q.empty()&&i-q.front()>k-1){
            	q.pop_front();
            }
            q.push_back(i);
            result.push_back(nums[q.front()]);

        }
        
        return result;
    }
};
*/

int main(){

	return 0;
}