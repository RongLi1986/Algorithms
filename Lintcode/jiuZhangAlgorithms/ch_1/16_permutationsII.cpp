/*
Permutations II

Given a list of numbers with duplicate number in it. Find all unique permutations.

For nums = [1,2,2], the permutations are:

[
  [1,2,2],
  [2,1,2],
  [2,2,1],
]
*/

#include <iostream>
using namespace std;

/*
firstly it need sort
backtrack + dfs 
O(n)
one visitMap needed to keep which item is visited
*/

lass Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > res;
        if(nums.size()==0) return res;
        vector<int> tmp;
        vector<int> visit(nums.size(),0);
        
        sort(nums.begin(),nums.end());
        
        helper(res,nums,visit,tmp);
        
        return res;
    }
    
    void helper(vector<vector<int> >& res, vector<int> &nums, vector<int>& visit, vector<int>& tmp){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){

            /* 
              avoid duplicated number, if nums[i-1] not in list
              stop.
            */
            if(i>0 && nums[i]==nums[i-1] && visit[i-1]==0)
                continue;
            
            if(visit[i]==0){
                visit[i]=1;
                tmp.push_back(nums[i]);
                helper(res,nums,visit,tmp);
                tmp.pop_back();
                visit[i]=0;
            }
        }
        
        return;
    }
};

int main(){

  Solution s;

  //test
  /*
  [1,2,2]
  
  //corner case
  []
  
  */

  cout<<s.permute(nums)<<endl;


	return 0;
}