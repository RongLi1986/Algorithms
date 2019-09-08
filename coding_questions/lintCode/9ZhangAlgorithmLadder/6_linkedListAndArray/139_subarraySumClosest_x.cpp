/*
Subarray Sum Closest

Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and 
last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].
*/

/*

*/

bool myfunction (pair<int, int> i,pair<int,int> j) { 
    return (i.second < j.second); 
}

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest_n2(vector<int> nums){
        // write your code here
        int minVal = INT_MAX;
        vector<int> res(2,0);
        
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                //sum = getSum(nums,sum,i,j);
                sum = sum + nums[j];
                if(minVal> abs(sum)){
                    minVal = abs(sum);
                    res[0] = i;
                    res[1] = j;
                    if(minVal==0)
                        return res;
                }
            }
        }
        
        return res;
    }
    
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        if(nums.empty())
            return vector<int>(0,0);
            
        int minVal = INT_MAX;
        vector<int> res(2,0);
        
        if(nums.size() == 1)
            return res;
        
        vector< pair<int,int> > subArraySum;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            pair<int, int> node;
            sum+=nums[i];
            node = make_pair(i,sum);
            subArraySum.push_back(node);
        }
        
        sort(subArraySum.begin(), subArraySum.end(), myfunction);
        
        for(int i=1;i<subArraySum.size();i++){
            //cout<<subArraySum[i].second<<" ";
            if(minVal>subArraySum[i].second-subArraySum[i-1].second){
                //cout<<"kk: "<<minVal<<endl;
                minVal = subArraySum[i].second-subArraySum[i-1].second;
                //cout<<"subArraySum[i] "<<subArraySum[i].second<<" "<<subArraySum[i].first<<endl;
                //cout<<"subArraySum[i-1] "<<subArraySum[i-1].second<<" "<<subArraySum[i-1].first<<endl;
                res[0] = min(subArraySum[i].first, subArraySum[i-1].first)+1; 
                //cout<<"res[0] "<<res[0] <<endl;
                res[1] = max(subArraySum[i].first, subArraySum[i-1].first); 
                //cout<<"res[1] "<<res[1] <<endl;
            }
                
        }
        //cout<<endl;
        
        return res;
    }
};
