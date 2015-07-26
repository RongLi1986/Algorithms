/*
Combination Sum II  
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution_old {
private:
    vector<vector<int> > out;
    set<vector<int> > tmp;  //avoid dup
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        int size=candidates.size();
        recusiveCombinSum(candidates,size, v,target, 0);
        
        set<vector<int> >::iterator it=tmp.begin();
        //cout<<tmp.size()<<endl;
        for(;it!=tmp.end();++it){
            out.push_back(*it);
        }
        
        return out;

    }

    void recusiveCombinSum(vector<int> &candidates, int size, vector<int> v,int target, int index){
        if(target==0){
            tmp.insert(v);
            return;
        }
        for(int i=index;i<size;i++){
            if(target>=candidates[i]){
                int nextTarget=target-candidates[i];
                v.push_back(candidates[i]);
                recusiveCombinSum(candidates, size, v, nextTarget, i+1);
                v.pop_back();
            }else
                return;
            
        }

        return;
    }
};


/*
backTracking by recursive
for each number verify with target
target==0 push in vector
target<0 stop
target>0 goto recursive: 
(this question don't allow repeated number)
so we directly pass i+1 into recrusive number 

trick part:
*/

class Solution {
private:
    vector<vector<int> > out;
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        recursiveTrack(candidates,0,target,tmp);
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
                recursiveTrack(candidates,i+1,left,tmp);
                tmp.pop_back();
                while(i<candidates.size()-1&&candidates[i]==candidates[i+1])  //kill repeated item
                    i++;

            }else
                return;
        }
        
        return;
    }
};


int main(){
	
	Solution s;
	vector<int> num={1,1};
	int target=1;
	vector<vector<int> >v=s.combinationSum2(num,target);
	
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