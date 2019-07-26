/*
332. Reconstruct Itinerary   My Submissions QuestionEditorial Solution
Total Accepted: 8424 Total Submissions: 35350 Difficulty: Medium
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

/*
dfs + tree
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> map;
 
        return dfs_both(root, map);
    }
    
    int dfs_both(TreeNode* root,unordered_map<TreeNode*,int> &map){
        
        if(map.find(root)!=map.end()) 
            return map[root];
        
        int maxVal =max(dfs(root, 0, map),dfs(root, 1, map));
        
        map[root]=maxVal;
        
        return maxVal;
    }
    
    int dfs(TreeNode* root, int select, unordered_map<TreeNode*,int> &map){
        if(root==NULL)
            return 0;
        
        if(select==1){  //root is exculde
            return dfs(root->left,0, map)+dfs(root->right,0, map)+ root->val; 
        }else{ //root is include
            return dfs_both(root->left, map)+dfs_both(root->right, map);
        }
    }
};

int main(){

    return 0;
}