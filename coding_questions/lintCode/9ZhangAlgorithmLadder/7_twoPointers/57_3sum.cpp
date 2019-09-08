/*
3Sum

Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)
*/

/*

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
                        myMap[nums[j]]=1;       //put in hashmap
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