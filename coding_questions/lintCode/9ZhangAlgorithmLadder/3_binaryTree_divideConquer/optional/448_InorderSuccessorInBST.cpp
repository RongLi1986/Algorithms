/*
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

 Notice

If the given node has no in-order successor in the tree, return null.
*/


/*
recursive solution
non-recursive solution
 */


#include <iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
sol1: inorder traverse and put them into vector
then scan it find target and its successor

running time O(n)
*/

class Solution {
private:
    vector<TreeNode*> res;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        res=inorderTraversal(root);
        
        for(int i=0;i<res.size();i++){
            if(res[i]==p){
                if(i==res.size()-1)
                    return NULL;
                return res[i+1];
            }
        }
                
        return NULL;
    }
    
    vector<TreeNode*> inorderTraversal(TreeNode *root) {
        // write your code here
        
        inorderTraversalRecursive(root);
        
        return res;
    }
    
    void inorderTraversalRecursive(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorderTraversalRecursive(root->left);
        res.push_back(root);
        inorderTraversalRecursive(root->right);
        
        return;
    }
};


/*
sol2
case1:

*/
class Solution {
private:
    vector<TreeNode*> res;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        
        TreeNode* ptr=root;
        TreeNode* successor = NULL;
        while(ptr!=NULL && ptr->val!= p->val){
            if(ptr->val > p->val){
                successor = ptr;
                ptr = ptr->left;
            }else{
                ptr = ptr->right;
            }
        }
        
        if(ptr==NULL)
            return successor;
        
        if(ptr==p){
            if(ptr->right!=NULL){
                ptr = ptr->right;
                successor = ptr;
                while(ptr!=NULL){
                    successor = ptr;
                    ptr=ptr->left;
                }
                return successor;
            }else{
                return successor;
            }
            
        }
        
        return NULL;
    }
};

int main(){

	return 0;
}