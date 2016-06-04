/*
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3
For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4
*/

#include <iostream>
using namespace std;

/*
from jiuZhang:
￼￼  将n个数看做n个木桩,目的是从某个木桩出发,从前向后,从低往高,看做 多能踩多少个木桩。

state: f[i] 表示(从任意某个木桩)跳到第i个木桩,最多踩过多少根木桩 
function: f[i] = max{f[j] + 1}, j必须满足 j < i && nums[j] <= nums[i] 
initialize: f[0..n-1] = 1
answer: max{f[0..n-1]}
 */

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.empty()) 
            return 0;
        
        vector<int> times(nums.size(),1);
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<=nums[i] && times[j] >= times[i])
                    times[i]=times[j] + 1;
            }
        }
        
        int maxVal=INT_MIN;
        for(int i=0; i < times.size() ;i++)
            if(times[i]>maxVal)
                maxVal=times[i];
        
        return maxVal;
    }
};

int main(){

	return 0;
}