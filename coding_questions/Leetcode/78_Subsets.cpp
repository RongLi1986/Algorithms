/*
Subsets 
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

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
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
backtracking
首先我们需要对集合排序，对于一个n元素的集合，首先我们取第一个元素，加入子集合中，后面的n - 1个
元素可以认为是第一个元素的子节点，我们依次遍历，譬如遍历到第二个元素的时候，后续的n - 2个元素
又是第二个元素的子节点，再依次遍历处理，直到最后一个元素，然后回溯，继续处理。处理完第一个元
素之后，我们按照同样的方式处理第二个元素。
*/

class Solution1 {
public:
  vector<vector<int> > out;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.empty()) {
            return out;
        }

        sort(S.begin(),S.end());

        vector<int> sub;
        out.push_back(sub);

        findSubsets(S, 0, sub);

        return out;
    }

    void findSubsets(vector<int> &S, int startIndex, vector<int>& sub){
        if(startIndex==S.size()){
            return;
        }

        for(int i=startIndex;i<S.size();i++){
            sub.push_back(S[i]);
            out.push_back(sub);
            findSubsets(S, i+1, sub);
            sub.pop_back();
        }
    }
};




class Solution_old {
private:
	vector<vector<int> > out;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int size=S.size();

        vector<int> empty={};
        out.push_back(empty);
        vector<int> sub;
        for(int i=0;i<size;i++){
        	findSubsets(S, size, i, sub);
        }
        
        return out;
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
    		out.push_back(sub);
    	}

    }
};

int main(){
	vector<int> S={1,2,3,4,5,6,7,8,10,0};

	Solution1 s;
	vector<vector<int> > out=s.subsets(S);

    /*
	int size=out.size();
	for(int i=0;i<size;i++){
		int sizeR=out[i].size();
		for(int j=0;j<sizeR;j++)
			cout<<out[i][j]<<" ";
		cout<<endl;
	}
    */


	return 0;
}