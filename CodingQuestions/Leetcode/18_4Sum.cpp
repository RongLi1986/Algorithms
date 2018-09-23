/*
4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/


/*
use two index left and right, and move them by compare nums[left]+nums[right]+num[1]+num[2] with target
nums[left]+nums[right] < target, move left
nums[left]+nums[right] > target, move right
also handle repeat case
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int> > out;
	set<vector<int> > tmp;
public:

	vector<vector<int> > fourSum(vector<int> &num, int target) {
    	sort(num.begin(),num.end());
    	int size=num.size();
    	//int chooseNum;
    	for(int i=0;i<size-1;i++){
    		if(i == 0 || num[i] > num[i - 1]){
	    		for(int j=i+1;j<size;j++){
	    			if(j == i+1|| num[j] > num[j - 1]){
	    				twoSumCheck(num,num[i],num[j],target,j,size);
	    			}
	    		}
    		}
    	}

    	return out;
    }

	void twoSumCheck(vector<int> &numbers, int one,int two, int target, int block, int vectorLength){
		vector<int> output;
		int findValue;
		int left=block+1;
		int right=vectorLength-1;

		while(left<right){

			if(numbers[left]+numbers[right]+one+two==target){
				
				output.push_back(one);
				output.push_back(two);
				output.push_back(numbers[left]);
				output.push_back(numbers[right]);
				
				out.push_back(output);
				output.clear();
				int old_right=right;
				int old_left=left;

				//habdle repeated case
				while(numbers[old_left]==numbers[left]&& left<vectorLength){
					left++;
				}

				while(numbers[old_right]==numbers[right]&& right>0){
					right--;
				}

			}else if(numbers[left]+numbers[right]+one+two<target){

				left++;
			}else{

				right--;

			}

		}
	}

};

int main(){
	vector<int> ss= {1,0,-1,0,-2, 2};
	vector<int> ss1= {0,0,0,0,0, 0};  //0
	vector<int> ss2= {-1,0,1,2,-1,-4}; //-1
	Solution s;
	

	vector<vector<int> >v=s.fourSum(ss1,-1);
	
	if(!v.empty()){
		int size=v.size();
		int sizeRow=v[0].size();
		
		for(int i=0;i<size;i++){
			for(int j=0;j<sizeRow;j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}