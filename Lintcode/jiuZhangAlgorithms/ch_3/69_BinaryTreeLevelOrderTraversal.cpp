/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 bfs + dummy node
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
class Solution {
private:
    vector<vector<int> > res; 
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        if(root==NULL) return res;
        
        TreeNode* dummyNode = new TreeNode(INT_MAX);
        
        deque<TreeNode*> queue;
        vector<int> level;
        queue.push_back(root);
        queue.push_back(dummyNode);
        
        while(!queue.empty()){
            TreeNode* tmp=queue.front();
            //cout<<tmp->val<<endl;
            if(tmp->val==INT_MAX){ //reach level end
                res.push_back(level);
                level.clear();
                queue.pop_front();
                queue.push_back(dummyNode);
                if(queue.size()==1) //only dummy node, leave loop
                    break;
            }else{     //normal nodes
                level.push_back(tmp->val);
                if(tmp->left)
                    queue.push_back(tmp->left);
                if(tmp->right)
                    queue.push_back(tmp->right);
                queue.pop_front();
            }
        }
        
        delete dummyNode;
        
        return res;
    }
};


int main(){

	return 0;
}