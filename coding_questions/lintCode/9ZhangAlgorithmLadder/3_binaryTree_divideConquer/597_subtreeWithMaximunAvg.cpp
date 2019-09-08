/*
Subtree with Maximum Average

Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

 Notice

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum average.

Example
Given a binary tree:

     1
   /   \
 -5     11
 / \   /  \
1   2 4    -2 
return the node 11.
*/

/*
recursive + divide conque
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right>;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right> = NULL;
 *     }
 * }
 */
class Solution {
    double maxAvg = INT_MIN;
    TreeNode* targetNode = NULL;
public:
    /**
     * @param root the root of binary tree
     * @return the root of the minimum subtree
     */
    TreeNode* findSubtree2(TreeNode* root) {
        // Write your code here
        helper (root);
        
        return targetNode;
    }
    
    //return (sum, numberNodes)
    vector<int> helper(TreeNode* root){
        vector<int> res(2,0);
        if(root==NULL)
            return res;
        int numberNodes = 1;
        int sum = root->val;
        
        if(root->left != NULL){
            vector<int> leftSubTree = helper(root->left);
            double leftAvg = (double) leftSubTree[0]/leftSubTree[1];
            //cout<<leftAvg<<endl;
            if(leftAvg > maxAvg){
                maxAvg = leftAvg;
                targetNode = root->left;
            }
            sum += leftSubTree[0];
            numberNodes += leftSubTree[1];
        }
        
        if(root->right!= NULL){
            vector<int> rightSubTree = helper(root->right);
            double rightAvg = (double) rightSubTree[0]/rightSubTree[1];
            //cout<<rightAvg<<endl;
            if(rightAvg > maxAvg){
                maxAvg = rightAvg;
                targetNode = root->right;
            }
            sum += rightSubTree[0];
            numberNodes += rightSubTree[1];
        }
        
        double avg = (double) sum/numberNodes;
        //cout<<avg<<endl;
        if(avg > maxAvg){
            maxAvg = avg;
            targetNode = root;
        }
        
        res[0] = sum;
        res[1] = numberNodes;
        
        return res;
        
    }
};

int main(){

	return 0;
}