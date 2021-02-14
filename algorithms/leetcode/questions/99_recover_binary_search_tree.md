# 99. Recover Binary Search Tree

## Question link
(https://leetcode.com/problems/recover-binary-search-tree/)

## Question Description
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example 1:
![Image](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)

> Input: root = [1,3,null,null,2]
> Output: [3,1,null,null,2]
> Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
![Image](https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg)

> Input: root = [3,1,4,null,null,2]
> Output: [2,1,4,null,null,3]
> Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 
Constraints:
The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1

## 解题思路
DFS

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
public:
    void recoverTree(TreeNode* root) {
        int first = INT_MAX;
        int last  = INT_MAX;
        
        //serialize tree to list
        vector<TreeNode*> list;
        DFS(root, list);
        
        if(!list.empty()){
            //find two swap node
            for(int i = 0; i < list.size() - 1; i++){
                if(list[i]->val > list[i + 1]->val){
                    if(first == INT_MAX){
                        first = i;
                        last  = i + 1;
                    }else{
                        last = i + 1;
                    }
                }
            }
            
            //found and swap val
            if(first != INT_MAX && last != INT_MAX){
                int t = list[first]->val;
                list[first]->val = list[last]->val;
                list[last]->val = t;
            }
        }
        
        return;
    }
    
    void DFS(TreeNode* root, vector<TreeNode*>& list){
        if(root==NULL) return;
        
        DFS(root->left, list);
        list.push_back(root);
        DFS(root->right, list);
        
        return;
    }
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(n)