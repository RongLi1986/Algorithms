/*
Medium 3 Sum Show result 

19% Accepted
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Have you met this question in a real interview? Yes
Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
three sum: this question is extending from two sum, we need add a outer loop, 
and need to avoid repeated numbers.
how to avoid repeated numbers?
make sure nums[i]<nums[i+1]
hasmap[findValue-nums[j]] need to delete after find this value.

two sum
keep a hashmap, number value as key and number index as its value
travese array if we cannot find key in hasmap(for now no number can match sum with it), 
insert it.
otherwise, put its index and item's value in hashmap in output array

running time:O(n). O(n) space
*/ 

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > res;
        vector<int> output;  //output vector
		unordered_map<int,int> myMap;  //<key, value>: keep value and index
		int findValue;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
		    myMap.clear();
		    //avoiding i has repeated number
		    if(i == 0 || nums[i] > nums[i - 1]){
    		    findValue = 0-nums[i];
    		    for(int j=i+1;j<nums.size();j++){
    		        int tmp=findValue-nums[j];
    		        if(myMap.find(tmp)==myMap.end()){  //not find 
    				    myMap[nums[j]]=1;      	//put in hashmap
        			}else{
        			    if(myMap[tmp]==1){
            				output.push_back(nums[i]); //save in output vector
            				output.push_back(tmp);
            				output.push_back(nums[j]);	
            				res.push_back(output);
            				output.clear();
            				//avoid j has repeated number
            	            myMap[tmp]=0;			
        			    }
        			}
    		    }
		    }
		}
		
		return res;
    }
};


int main(){
	vector<int> numbers;

	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	

	int target=6;

	Solution s;
	s.twoSum(numbers,target);

	return 0;
}