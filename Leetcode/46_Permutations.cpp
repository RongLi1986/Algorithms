/*
Permutations 
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//using nextPermutation way
class Solution {
private:
	vector<vector<int> > out;
public:
    vector<vector<int> > permute_nextPermutation(vector<int> &num) {
        sort(num.begin(),num.end());
        out.push_back(num);
        int size=num.size();
        int i=0;
        while(i!=-1){
        	i=nextPermutation(num, size);
        }

        return out;
    }

    int nextPermutation(vector<int> &num, int size) {
        int changeIndex=-1;
        
        for(int i=size-1;i>0;i--){
            if(num[i]>num[i-1]){
                changeIndex=i-1;
                for(int j=size-1;j>changeIndex;j--){
                	if(num[j]>num[changeIndex]){
                		swap(num, j, changeIndex);
                		sort(num.begin()+changeIndex+1, num.end());
                		out.push_back(num);
                		return changeIndex;
                	}
                }
            }
        }
        
        if(changeIndex==-1){  //no larger number
        	//out.push_back(num);
            //sort(num.begin(),num.end());
            return changeIndex;

        }
    }
    
    void swap(vector<int> &num,int origIndex, int changeIndex){
    	//cout<<"num"<<endl;
    	//cout<<origIndex<<" "<<changeIndex<<endl;
        int tmp=num[changeIndex];
        num[changeIndex]=num[origIndex];
        num[origIndex]=tmp;
    }

    vector<vector<int> > permute(vector<int> &num) {

        return out;
    }
};

/*
backtracking
need a map for keeping used number
*/
class Solution_normal {
private:
    vector<vector<int> > out;
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> tmp;
        vector<int> map(nums.size(),0);
        recursivePermute(nums,tmp,map);
        
        return out;
    }
    
    void recursivePermute(vector<int>& nums,vector<int> tmp, vector<int> map){
        if(tmp.size()==nums.size()){
            out.push_back(tmp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(map[i]==0){
                map[i]=1;
                tmp.push_back(nums[i]);
                recursivePermute(nums,tmp,map);
                tmp.pop_back();
                map[i]=0;
            }
        }

        return;
    } 
};

int main(){
	Solution s;
	vector<int> v={1,3,2}; 
	
	vector<vector<int> > out=s.permute(v);

	int size=out.size();

	for(int i=0;i<size;i++){
		int sizeR=out[0].size();
		for(int j=0;j<sizeR;j++)	
			cout<<out[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}