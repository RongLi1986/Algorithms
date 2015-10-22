/*
Kth Smallest Element in a BST 
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

*/

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
inorder traverse and put all value 
in vector

return vector[k-1]

can we find it directly from tree
*/

class Solution {
private:
    vector<int> v;
public:
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root);
        
        return v[k-1];        
    }
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
        return;
    }
};



int main(){

	return 0;
}