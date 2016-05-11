/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */


/*
recursive and keep depth's value, find larger one from left leaf and right leaf
 */


#include <iostream>
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

//dfs recursive way 
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root == NULL) 
            return 0;
        
        return maxDepthHelper(root);
        
    }
    
    int maxDepthHelper(TreeNode *root){
        if(root==NULL) 
            return 0;
            
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);

        return max(left, right);
    }
};

//dfs non-recursive
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root == NULL) 
            return 0;
        
        stack<TreeNode* > nodeStk;
        stack<int> layerStk;
        int maxDepthCount = 0;

        nodeStk.push(root);
        layerStk.push(1);
        
        int count;
        while(!nodeStk.empty()){
            TreeNode* tmp = nodeStk.top();
            nodeStk.pop();

            count = layerStk.top();
            layerStk.pop();

            //tmp is end of one branch
            if(tmp->left==NULL && tmp->right ==NULL){
                if(count>maxDepthCount)
                    maxDepthCount=count;
            }

            if(tmp->right!=NULL){
                nodeStk.push(tmp->right);
                count++;
                layerStk.push(count);
                count--;
            }
            

            if(tmp->left!=NULL){
                nodeStk.push(tmp->left);
                count++;
                layerStk.push(count);
                count--;
            }

        }

        return maxDepthCount;        
    }
};

//bfs non-recursive
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root == NULL) 
            return 0;
        
        int maxDepthCount = 0;

        deque<TreeNode* > nodeQue;
        nodeQue.push_back(root);
        
        //use it as level flag
        TreeNode* dumpNode = new TreeNode(INT_MAX);
        nodeQue.push_back(dumpNode);

        while(1){
            TreeNode* tmp = nodeQue.front();
            nodeQue.pop_front();


            //tmp is end of one level
            if(tmp->val==INT_MAX){
                maxDepthCount++;
                nodeQue.push_back(dumpNode);
                if(nodeQue.size()==1) 
                    break;
            }

            if(tmp->left!=NULL){
                nodeQue.push_back(tmp->left);
            }
            
            if(tmp->right!=NULL){
                nodeQue.push_back(tmp->right);
            }

        }

        return maxDepthCount;        
    }
};



int main(){

	return 0;
}