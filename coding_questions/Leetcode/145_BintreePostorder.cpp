/*
Binary Tree Postorder Traversal 
Given a binary tree, return the postorder traversal of 
its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
sol1:
recursive way

TODO: iterative way, maybe it need queue
*/


/**
 * Definition for binary tree
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 //recursive
class Solution_recursive {
private:
    vector<int> vect;
public:
    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        
        return vect;
    }
    
    void postorder(TreeNode *root) {
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        vect.push_back(root->val);
    }
    
};

//iterative

int main(){


	return 0;
}