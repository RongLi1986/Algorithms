/*
Binary Tree Preorder Traversal 
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
recursive way and iterative
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
 
//iterative by using stack
class Solution {
private:
    stack<TreeNode*> stk;
    vector<int> vect;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(root==NULL) return vect;
        
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* ptr=stk.top();
            stk.pop();
            vect.push_back(ptr->val);
            if(ptr->right!=NULL)
                stk.push(ptr->right);
            if(ptr->left!=NULL)
                stk.push(ptr->left);
            
        }
        
        return vect;
    }
};

 //recursive
class Solution_recursive {
private:
    vector<int> vect;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root);
        
        return vect;
    }
    
    void preorder(TreeNode *root) {
        if(root==NULL) return;
        
        vect.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
};


int main(){


	return 0;
}