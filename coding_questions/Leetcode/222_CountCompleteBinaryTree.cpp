/*
Count Complete Tree Nodes Total Accepted: 329 Total Submissions: 1816 My Submissions Question Solution 
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/


 //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TODO:
class Solution {
public:
    int countNodes(TreeNode* root) {
	    if(!root) return 0;
	    
	    //get height
	    TreeNode *temp = root;
	    //count is last level nodes' count
	    int height = 0, count = 0, level=0;
	    while(temp) {
	        temp = temp->left;
	        height ++;
	    }

	    /*
	    use temp to scan root left branch,
	    if left is complete binary tree, + number in count
	    and change to right tree.
	    finally, count should be last level node
	    */

	    temp = root;
	    level = height - 2;
	    while(level >= 0) {
	        TreeNode *left = temp->left;
	        for(int i = 0;i < level;i ++) {
	            left = left->right;
	        }
	        if(left) {
	            temp = temp->right;
	            count += (1 << level);
	        } else temp = temp->left;
	        level --;
	    }
	    if(temp) count ++;
	    return (1 << (height - 1)) -1 + count;
	}
};

/*
easy way is recursive solution
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int heightLeft=0;
        TreeNode* leftNode=root;
        while(leftNode!=NULL){
            heightLeft++;
            leftNode=leftNode->left;
        }
        int heightRight=0;
        TreeNode* rightNode=root;
        while(rightNode!=NULL){
            heightRight++;
            rightNode=rightNode->right;
        }
        
        if(heightLeft==heightRight){
            return (1 << heightLeft) - 1;
        }else
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};