/*
Given a list of numbers, return all possible permutations.

For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
using namespace std;

/*
backtrack + dfs 
O(n)
one visitMap needed to keep which item is visited
*/

class Solution {
private:
    vector<vector<int> > res;

public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if (nums.empty())
            return res;

        vector<int> visitMap(nums.size(), 0);
        vector<int> subset;

        recursiveDfs(nums, subset, visitMap);
        return res;
    }

    void recursiveDfs(vector<int> &nums, vector<int>& subset, vector<int>& visitMap){
        // put subset into res, when it reach nums' size
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size() ; i++) {
            if (visitMap[i] != 1) {
                subset.push_back(nums[i]);
                visitMap[i]=1;
                recursiveDfs(nums, subset, visitMap);
                subset.pop_back();
                visitMap[i]=0;
            }
        }

        return;
    }
};

int main(){

  Solution s;

  //test
  /*
  [1,2,3]
  
  //corner case
  []
  
  */

  cout<<s.permute(nums)<<endl;


	return 0;
}