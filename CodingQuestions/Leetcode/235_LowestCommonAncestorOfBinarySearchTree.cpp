/*
Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the 
lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

/*
for bst, we could know children nodes'location by compare their value.
smaller than parent, in left.
bigger than parent, in right.
so, we can compare root's value. and find common ancestor
*/


#include <iostream>

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


class Solution_RecursiveWay {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        TreeNode* small=(p->val > q->val)?q:p;
        TreeNode* big=(p->val> q ->val)?p:q;
        if(root->val>=small->val&&root->val<=big->val)
            return root;
        else if(root->val<=small->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};

class Solution_iterativeWay {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* parent =root;
        if(root==NULL) return parent;
        TreeNode* small=(p->val>=q->val)?q:p;
        TreeNode* large=(p->val>=q->val)?p:q;
        
        while(parent!=NULL){
            if(parent->val<small->val){
                parent=parent->right;
            }else if(large->val<parent->val){
                parent=parent->left;
            }else{
                return parent;
            }
        }

        return parent;
    }
};

int main(){
    
	return 0;
}