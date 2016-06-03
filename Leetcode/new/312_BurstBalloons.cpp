/*
310. Minimum Height Trees   My Submissions QuestionEditorial Solution
Total Accepted: 11071 Total Submissions: 41666 Difficulty: Medium
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?
Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Credits:
Sp
 */

/*
caculate each node's degree.
and put them into a queue whose degree is 1.
then loop this queue, each node in this queue,
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//2D DP
class Solution {
private:
    int res;
public:
    int maxCoins(vector<int>& nums){
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(),0));
        
        int len=1;
        
        for(int len=0;len<nums.size()-2;++len){
            for(int i=1;i<nums.size()-1-len;i++){
                int j=len+i;
                for(int x=i;x<=j;x++){
                    dp[i][j]=max(dp[i][j],dp[i][x-1]+nums[i-1]*nums[x]*nums[j+1]+dp[x+1][j]);
                }
            }
        }
        
        /*
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                cout<<dp[i][j]<<" ";      
            }
            cout<<endl;
        }
        */
        
        return dp[1][nums.size()-2];
    }
    
    int maxCoins2(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        res=0;
        maxCoinsHelper(nums, 0);
        
        return res;
    }
    
    void maxCoinsHelper(vector<int>& nums, int tmpRes){
        if(nums.size()==2){
            if(tmpRes>res){
                res=tmpRes;
            }
        }
        
        for(int i=1;i<nums.size()-1;i++){
            int product=nums[i-1]*nums[i]*nums[i+1];
            tmpRes+=product;
            vector<int> copyVec=nums;
            copyVec.erase(copyVec.begin()+i);
            maxCoinsHelper(copyVec, tmpRes);
            tmpRes-=product;
        }
    }
};

//backtrace + recursive (TLE)
class Solution {
private:
    int res;
public:
    int maxCoins2(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        res=0;
        maxCoinsHelper(nums, 0);
        
        return res;
    }
    
    void maxCoinsHelper(vector<int>& nums, int tmpRes){
        if(nums.size()==2){
            if(tmpRes>res){
                res=tmpRes;
            }
        }
        
        for(int i=1;i<nums.size()-1;i++){
            int product=nums[i-1]*nums[i]*nums[i+1];
            tmpRes+=product;
            vector<int> copyVec=nums;
            copyVec.erase(copyVec.begin()+i);
            maxCoinsHelper(copyVec, tmpRes);
            tmpRes-=product;
        }
    }
};

int main(){

    return 0;
}