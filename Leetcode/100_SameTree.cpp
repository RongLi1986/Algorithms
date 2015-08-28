/*
Same Tree

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/*
travse and compare each item
*/


/*
 * Definition for binary tree
 */
#include <iostream>
 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL && q==NULL){
        	return true;
        }else if(p==NULL&&q!=NULL){
        	return false;
        }else if(p!=NULL&&q==NULL){
        	return false;
        }else{
	    	if(p->val == q->val){
	    		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	    	}else
	    		return false;
	    }
    }
};

int main(){
	//create tree and test it

	return 0;
}