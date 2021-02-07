# 94. Binary Tree Inorder Traversal

## Question link
(https://leetcode.com/problems/binary-tree-inorder-traversal/)

## Question Description
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
![Image](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
> Input: root = [1,null,2,3]
> Output: [1,3,2]

Example 2:

> Input: root = []
> Output: []

Example 3:

> Input: root = [1]
> Output: [1]

Example 4:
![Image](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)
> Input: root = [1,2]
> Output: [2,1]

Example 5:
![Image](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)
> Input: root = [1,null,2]
> Output: [1,2]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up:

Recursive solution is trivial, could you do it iteratively?

## 解题思路
dfs
recursive
stack

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

class Solution{
private:
    vector<int> res;
    vector<TreeNode*> stack;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode* ptr = root;
        
        while(ptr != NULL || !stack.empty()){
            if(ptr != NULL){
                stack.push_back(ptr);
                ptr = ptr->left;
            }else{
                ptr = stack[stack.size() - 1];
                stack.pop_back();
                res.push_back(ptr->val);
                ptr = ptr->right;
            }
        }

        return res;
    }
};
```

## Time Complexity Analysis