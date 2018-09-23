/*
Combination Sum III 
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/



/*
solution: recursive & backtrack 

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int> > out;
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> v;
        vector<int> candidates;
        for(int i=1;i<10;i++){
            candidates.push_back(i);
        }
        int size=candidates.size();
        recusiveCombinSum(candidates,v,n,0,0,k);

        return out;
    }

    void recusiveCombinSum(vector<int> &candidates, vector<int> v,int target, int index, int count, int k){
        if(count==k){
            if(target==0)
                out.push_back(v);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target){
                v.push_back(candidates[i]);
                recusiveCombinSum(candidates,v,target-candidates[i],i+1,count+1,k);
                v.pop_back();
            }else{
                //the candidates is sorted, so next number also larger than target
                return;
            }
        }
        
        return;
    }
};
int main(){
	Solution s;
    vector<vector<int> > out=s.combinationSum3(3,7);
	
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}








