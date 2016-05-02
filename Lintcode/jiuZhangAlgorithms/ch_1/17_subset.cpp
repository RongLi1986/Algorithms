/*
Subsets
Given a set of distinct integers, return all possible subsets.

Notice
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
*/

#include <iostream>
using namespace std;

/*
backtrack + dfs 
O(n)
 */

class Solution {
private:
    vector<vector<int> > res;

public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        if (nums.empty())
            return res;

        vector<int> subset;
        
        recursiveDfs(nums, 0, subset);

        return res;
    }

    void recursiveDfs(vector<int> &nums, int startPos, vector<int> subset){
        //put each subset into result vector
        res.push_back(subset);

        for (int i = startPos; i < nums.size() ; i++) {
            subset.push_back(nums[i]);
            recursiveDfs(nums, i+1, subset);
            subset.pop_back();
        }

        return;
    }
};

int main(){

	return 0;
}