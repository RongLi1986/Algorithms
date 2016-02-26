/*
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
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