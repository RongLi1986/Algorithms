/*
Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

 Notice

Each element in the result must be unique.
The result can be in any order.
Have you met this question in a real interview? Yes
Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/

/*
merge
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        unordered_map<int, int> hashMap;
        vector<int> res;
        
        for(int i=0;i<nums1.size();i++){
            if(hashMap.find(nums1[i])==hashMap.end()){
                hashMap[nums1[i]]=1;    
            }
        }
        
        for( int j=0;j<nums2.size();j++){
            if(hashMap.find(nums2[j])!=hashMap.end() && hashMap[nums2[j]]==1){
                //cout<<hashMap[nums2[j]]<<endl;
                res.push_back(nums2[j]);
                hashMap[nums2[j]]=0;
            }
        }
        
        return res;
    }
};