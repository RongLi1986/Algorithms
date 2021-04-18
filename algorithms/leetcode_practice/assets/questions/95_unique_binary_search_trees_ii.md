# 95. Unique Binary Search Trees II

## Question link
(https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Question Description
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
![Image](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

> Input: n = 3
> Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:

> Input: n = 1
> Output: [[1]]

## 解题思路
BST
DFS recusive

## Code
```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int count;
public:
    vector<TreeNode *> generateTrees(int n) {
        count = 0;
        return numTrees(1, n);
    }

    vector<TreeNode *> numTrees(int start, int end) {
        vector<TreeNode *> out;
        if(start > end){
            out.push_back(NULL);
            return out;
        }

        count++;
        for(int i = start;i <= end; i++){
            vector<TreeNode *> leftNodes  = numTrees(start, i - 1);
            vector<TreeNode *> rightNodes = numTrees(i + 1, end);
            
            if(leftNodes.empty() && !rightNodes.empty()){
                for(int a = 0;i < rightNodes.size();a++){
                    TreeNode* root = new TreeNode(i);
                    root->right = rightNodes[a];
                    out.push_back(root);
                }
            }else if(rightNodes.empty() && !leftNodes.empty()){
                for(int a = 0;a < leftNodes.size();a++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNodes[a];
                    out.push_back(root);
                }
            }else if(!rightNodes.empty() && !leftNodes.empty()){
                for(int a = 0;a < leftNodes.size();a++){
                    for(int b = 0;b < rightNodes.size();b++){
                        TreeNode* root = new TreeNode(i);
                        root->left = leftNodes[a];
                        root->right = rightNodes[b];
                        out.push_back(root);
                    }
                }
            }else{
                TreeNode* root=new TreeNode(i);
                out.push_back(root);
            }
        }

        return out;
    }
};
```

## Time Complexity Analysis