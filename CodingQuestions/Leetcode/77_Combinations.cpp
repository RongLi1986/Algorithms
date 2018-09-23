/*
Combinations Total Accepted: 32446 Total Submissions: 106622 My Submissions Question Solution 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
same with combination Sum
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution_old {
private:
	vector<vector<int> > out;
public:
	//very slow
    vector<vector<int> > combine(int n, int k) {
        vector<int> s;
        for(int i=0;i<n;i++)
        	s.push_back(i+1);

        //for(int i=0;i<n;i++){
        	vector<int> tmp;

        	combine(s,0, tmp, k);
       // }

        return out;
    }

    void combine(vector<int> v, int index, vector<int> tmp, int k){
    	if(k==0) {
    		out.push_back(tmp);
    	}
    	if(index>=v.size()) return;

    	for(int i=index;i<v.size();i++){
	    	tmp.push_back(v[i]);
	    	combine(v,i+1,tmp,k-1);
	    	tmp.pop_back();
    	}

    	return;

    }
};



class Solution {
private:
    vector<vector<int> > out; 
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        recursiveBT(n,k,1,tmp);  
        return out;
    }
    
    void recursiveBT(int n, int k, int start, vector<int> tmp){
        if(k==0){
            out.push_back(tmp);
            return;
        }
        
        for(int i=start;i<n+1;i++){
            tmp.push_back(i);
            recursiveBT(n,k-1,i+1,tmp);
            tmp.pop_back();
        }
        
        return;
    }
};


/*

The idea is that C(n,k) = C(n-1, k-1) U n + C(n-1,k), do you get this?

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {

        vector<vector<int> > result;
        if (n < 1 || k <1 || k > n)
        {
            return result;
        }

        result = combine(n-1, k-1);

        if(result.empty())
        {
            result.push_back(vector<int>{n});
        }
        else
        {
            for (vector<vector<int> >::iterator it = result.begin();
                    it!= result.end(); it++)
            {
                it->push_back(n);
            }
        }
        vector<vector<int> > result2 = combine(n-1, k);
        result. insert(result.end(), result2.begin(), result2.end());

        return result;
    }
};
*/

int main(){
	Solution s;

	vector<vector<int> > out=s.combine(4,0);

	int sizeR=out.size();
	int sizeW=out[0].size();

	for(int i=0;i<sizeR;i++){
		for(int j=0;j<sizeW;j++){
			cout<<out[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}