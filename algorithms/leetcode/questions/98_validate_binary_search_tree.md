# 98. Validate Binary Search Tree

## Question link
(https://leetcode.com/problems/validate-binary-search-tree/)

## Question Description
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

![Image](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
> Input: root = [2,1,3]
> Output: true

Example 2:

![Image](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
> Input: root = [5,1,4,null,null,3,6]
> Output: false
> Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1

## 解题思路
dfs travsal
recusive

## Code
```c++
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
private:
    vector<int> res;
public:
    bool isValidBST(TreeNode* root) {
        in_order(root);
        int size = res.size()-1;
        for(int i = 0; i < size; i++){
            if(res[i] >= res[i + 1])
                return false;
        }
        
        return true;
    }
    
    void in_order(TreeNode* root){
        if(root == NULL) return;
        in_order(root->left);
        res.push_back(root->val);
        in_order(root->right);
        
        return;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
    
    bool valid(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;
        return valid(root->left, minVal, root->val) && valid(root->right, root->val, maxVal);
    }
};
```

## Time Complexity Analysis