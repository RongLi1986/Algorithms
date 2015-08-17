/*
Subsets II 
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
same with subSetI, it only need to avoid repeated numbers

*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int> > res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());

        vector<int> tmp;
        
        //push null vector
        res.push_back(tmp);
        
        findsubsetRe(nums,tmp,0);

        return res;
    }

    void findsubsetRe(vector<int>& nums,vector<int> tmp, int start){
        if(start==nums.size())
            return;
        
        for(int i=start;i<nums.size();i++){
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            findsubsetRe(nums,tmp,i+1);
            tmp.pop_back();

            //avoid repeated numbers
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
        }
    }
};




class Solution_old {
private:
	set<vector<int> > out;
	vector<vector<int> > output;
public:
	//use SET, please find better way
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        int size=S.size();

        vector<int> empty={};
        out.insert(empty);
        vector<int> sub;
        for(int i=0;i<size;i++){
        	findSubsets(S, size, i, sub);
        }
        
        set<vector<int> >::iterator itr=out.begin();
        while(itr!=out.end()){
        	output.push_back(*itr);
        	++itr;
        }


        return output;
    }

    void findSubsets(vector<int> &S, int size, int startIndex, vector<int> sub){
    	if(startIndex<size){
    		sub.push_back(S[startIndex]);
    		int i=startIndex+1;
    		while(i<=size){
    			findSubsets(S, size, i, sub);
    			i++;
    		}
    	}else{
    		out.insert(sub);
    	}

    }
};

int main(){
	vector<int> S={1,2,2};

	Solution s;
	vector<vector<int> > out=s.subsetsWithDup(S);

	int size=out.size();
	for(int i=0;i<size;i++){
		int sizeR=out[i].size();
		for(int j=0;j<sizeR;j++)
			cout<<out[i][j]<<" ";
		cout<<endl;
	}


	return 0;
}