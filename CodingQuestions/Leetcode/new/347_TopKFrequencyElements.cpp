/*
347. Top K Frequent Elements   My Submissions QuestionEditorial Solution
Total Accepted: 1561 Total Submissions: 3511 Difficulty: Medium
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Subscribe to see which companies asked this question
*/
 
/*
map iterator
using priority queue with my comparsion
O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class mycomparison{
public:
    mycomparison(){
        
    }
  
    bool operator() (const pair<int,int> &lhs, const pair<int,int>& rhs) {
        return lhs.second < rhs.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,mycomparison> mypq;
        vector<int> res;
        
        for (int i=0;i<nums.size();i++){
            if(hashMap.find(nums[i])!=hashMap.end()){ //found it
                hashMap[nums[i]]++;
            }else{ //not found
                hashMap[nums[i]]=1;
            }
        }
        
        
        for (std::unordered_map<int,int>::iterator it=hashMap.begin(); it!=hashMap.end(); ++it){
            //std::cout << it->first << " => " << it->second << '\n';
            std::pair <int,int> node;
            node=std::make_pair(it->first, it->second);
            mypq.push(node);
        }
        
        for(int i=0;i<k;i++){
            res.push_back(mypq.top().first);
            mypq.pop();
        }
        
        return res;
    }
};

int main(){

    return 0;
}