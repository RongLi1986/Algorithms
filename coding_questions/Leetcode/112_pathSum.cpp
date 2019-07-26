/*
Path Sum 
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/



/*
use DFS

*/


#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL){
                return false;
        }else{
            int temp=sum-root->val;
            if(root->left==NULL&&root->right==NULL){  //root to leap
                if(temp==0)
                    return true;
            }
          return hasPathSum(root->left,temp)||hasPathSum(root->right, temp);
        }
    } 
};

int main(){
	/*
	          5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
	
	return
	[
   		[5,4,11,2],
   		[5,8,4,5]
	]
	*/

	TreeNode* a=new TreeNode(5);
	TreeNode* b=new TreeNode(4);
	TreeNode* c=new TreeNode(8);
	TreeNode* d=new TreeNode(11);
	TreeNode* e=new TreeNode(7);
	TreeNode* f=new TreeNode(2);
	TreeNode* g=new TreeNode(13);
	TreeNode* h=new TreeNode(4);
	TreeNode* i=new TreeNode(5);
	TreeNode* j=new TreeNode(1);


	a->left=b;
	a->right=c;

	b->left=d;

	d->left=e;
	d->left=f;

	c->left=g;
	c->right=h;

	h->left=i;
	h->right=j;

	Solution s;
	cout<<s.hasPathSum(a,22)<<endl;


	return 0;
}