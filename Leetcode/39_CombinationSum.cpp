/*
Combination Sum Total Accepted: 30265 Total Submissions: 111143 My Submissions Question Solution 
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

/*
backTracking by recursive
for each number verify with target
target==0 push in vector
target<0 stop
target>0 goto recursive

trick part:
39 testset has a bug, I guess test cases are not include repeated item
in vector, such like, [2,2] 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int> > out;
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        recursiveTrack(candidates, 0, target, tmp);
        return out;
    }
    
    void recursiveTrack(vector<int>& candidates, int start, int target, vector<int> tmp){
        if(target==0){
            out.push_back(tmp);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            int left=target-candidates[i];
            if(left>=0){
                tmp.push_back(candidates[i]);
                recursiveTrack(candidates, i, left, tmp);
                tmp.pop_back();
                while(i<candidates.size()-1&&candidates[i]==candidates[i+1])  //kill repeated int vector item
                    i++;
            }else
                return;
        }
        
        return;
    }
};


int main(){
	
	Solution s;
	vector<int> num={2,3,6,7};
	int target=7;
	vector<vector<int> >v=s.combinationSum(num,target);
	
	if(!v.empty()){

		int size=v.size();
		
		
		for(int i=0;i<size;i++){
			int sizeRow=v[i].size();
			for(int j=0;j<sizeRow;j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	

	return 0;
}