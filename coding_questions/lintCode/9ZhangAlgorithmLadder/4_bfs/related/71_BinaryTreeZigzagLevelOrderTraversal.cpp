/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

/*
bfs level tranversal + reverse flag
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        // write your code here
        deque<TreeNode*> queue;
        vector<vector<int> > res;
        
        if(root==NULL)
            return res;
        
         //create a dump node
        TreeNode* dump=new TreeNode(INT_MAX);
        int reverseFlag = 0;
        
        queue.push_back(root);
        queue.push_back(dump);
       
        vector<int> tmp;
        while(1){
            TreeNode* node=queue.front();
            queue.pop_front();
            
            if(node->val==INT_MAX){
                if(reverseFlag==1){
                    reverse(tmp.begin(), tmp.end());
                    reverseFlag = 0;
                }else{
                    reverseFlag = 1;
                }
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

        return res;
    }
};

int main(){
	
	return 0;
}