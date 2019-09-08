/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.



For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

 Notice

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Have you met this question in a real interview? Yes
Example
given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/


/*
backtracking + DFS
*/

class Solution {
private:
    vector<vector<int> > res;
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        if(candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        reverse(candidates.begin(), candidates.end());
        vector<int> tmp;
        combinationSumHelper(candidates, 0, target, tmp);
        
        return res;
    }
    
    void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> tmp){
        if(target==0){
            if(!tmp.empty())
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            return;   
        }
        
        for(int i = start;i < candidates.size(); i++){
            int delta = target - candidates[i];
            //cout<<delta<<"="<<target<<"-"<<candidates[i]<<endl;
            if(delta>=0){
                tmp.push_back(candidates[i]);
                combinationSumHelper(candidates, i, delta, tmp);
                tmp.pop_back();
            }else{
                //combinationSumHelper(candidates, i+1, target, tmp);
            }
        }
        
        return;
    }
};