/*
Two Sum - Difference equals to target

Given an array of integers, find two numbers that their difference equals to a target value.
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

 Notice

It's guaranteed there is only one available solution

Have you met this question in a real interview? Yes
Example
Given nums = [2, 7, 15, 24], target = 5
return [1, 2] (7 - 2 = 5)
*/

/*
consider about target == 0 case
*/


class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> hashMap;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            //cout<<i<<endl;
            if(hashMap.find(target+nums[i])==hashMap.end()){
                //cout<<"kk"<<nums[i]<<i+1<<endl;
                hashMap[nums[i]] = i+1;
            }else{
                res.push_back(hashMap[target+nums[i]]);
                res.push_back(i+1);
                break;
            }
            
            if(target!=0){
                if(hashMap.find(nums[i]-target)==hashMap.end()){
                    //cout<<"ll"<<nums[i]<<i+1<<endl;
                    hashMap[nums[i]] = i+1;
                }else{
                    res.push_back(hashMap[nums[i]-target]);
                    res.push_back(i+1);
                    break;
                }
            }
        }
        
        return res;
     }
};