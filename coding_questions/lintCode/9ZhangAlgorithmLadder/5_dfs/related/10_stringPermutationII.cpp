/*
String Permutation II

Given a string, find all permutations of it without duplicates.

Have you met this question in a real interview? Yes
Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].
*/

#include <iostream>
using namespace std;

class Solution {
private:
    vector<string > res;

public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
     
    vector<string> stringPermutation2(string& str) {
        // Write your code here
        vector<string> result;
        sort(str.begin(), str.end());
        result.push_back(str);
        while (next_permutation(str.begin(), str.end())) {
            result.push_back(str);
        }
        return result;
    }
    
    vector<string > stringPermutation2Duplicate(string& nums) {
        // write your code here
        if (nums.empty())
            return res;

        vector<int> visitMap(nums.size(), 0);
        string subset;

        recursiveDfs(nums, subset, visitMap);
        return res;
    }

    void recursiveDfs(string &nums, string& subset, vector<int>& visitMap){
        // put subset into res, when it reach nums' size
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size() ; i++) {
            if (visitMap[i] != 1) {
                string tmp = subset;
                tmp+=(nums[i]);
                visitMap[i]=1;
                recursiveDfs(nums, tmp, visitMap);
                
                visitMap[i]=0;
            }
        }

        return;
    }
};