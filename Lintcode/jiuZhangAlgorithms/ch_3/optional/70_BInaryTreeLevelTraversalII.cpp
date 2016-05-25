/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*/

/*
dump node
*/

#include <iostream>
#include <vector>
using namespace std;

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
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        deque<TreeNode*> queue;
        vector<vector<int> > res;
        
        if(root==NULL)
            return res;
        
         //create a dump node
        TreeNode* dump=new TreeNode(INT_MAX);
        
        queue.push_back(root);
        queue.push_back(dump);
       
        vector<int> tmp;
        while(1){
            TreeNode* node=queue.front();
            queue.pop_front();
            
            if(node->val==INT_MAX){
                res.push_back(tmp);
                tmp.clear();
                queue.push_back(node);
                if(queue.size()==1)
                    break;
            }else{
                tmp.push_back(node->val);
                if(node->left)
                    queue.push_back(node->left);
                
                if(node->right)
                    queue.push_back(node->right);
            }
        }
        
        delete(dump);
        
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
	
	return 0;
}