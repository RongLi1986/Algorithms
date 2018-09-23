/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.
 */


#include <iostream>
using namespace std;

/*
divided and conque
update max path value each time
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
    int maxValue;
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxBranchVal(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftVal = maxBranchVal(root->left);
        int rightVal = maxBranchVal(root->right);
        
        int value0 = leftVal + root->val;
        int value1 = rightVal + root->val;
        int value2 = leftVal + rightVal + root->val;
        
        int tmp = max(max(max(value0,value1),value2),root->val);
        
        //update max path value
        if(maxValue<tmp)
            maxValue = tmp;
            
        //return max branch value
        return max(max(value0,value1),root->val);
    }
    
    int maxPathSum(TreeNode *root) {
        // Write your code here
        maxValue = INT_MIN;
        
        maxBranchVal(root);
        
        return maxValue;
    }
};

int main(){

	return 0;
}