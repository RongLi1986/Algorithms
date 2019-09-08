/*
4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such 
that a + b + c + d = target?

Find all unique quadruplets in the array which gives the sum of target.

 Notice

Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example
Given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:

(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> output;  //output vector
        unordered_map<int,int> myMap;  //<key, value>: keep value and index
        int findValue;
        sort(nums.begin(),nums.end());
        for(int x=0;x<nums.size();x++){
            if(x == 0 || nums[x] > nums[x - 1]){
                for(int i=x+1;i<nums.size();i++){
                    myMap.clear();
                    //avoiding i has repeated number
                    if(i==x+1 || nums[i] > nums[i - 1]){
                        findValue = target -nums[i] -nums[x];
                        for(int j=i+1;j<nums.size();j++){
                            int tmp=findValue-nums[j];
                            if(myMap.find(tmp)==myMap.end()){  //not find 
                                myMap[nums[j]]=1;       //put in hashmap
                            }else{
                                if(myMap[tmp]==1){
                                    output.push_back(nums[x]);
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
            }
        }
        
        return res;
    }
};
