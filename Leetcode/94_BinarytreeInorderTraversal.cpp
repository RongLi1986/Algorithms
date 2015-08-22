/*
Binary Tree Inorder Traversal 
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
basic way is rescurive and iterative
iterative need a stack to keep parent node
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
 
//iterative
class Solution{
private:
    vector<int> res;
    vector<TreeNode*> stack;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode* ptr=root;
        
        while(ptr!=NULL||!stack.empty()){
            if(ptr!=NULL){
                stack.push_back(ptr);
                ptr=ptr->left;
            }else{
                ptr=stack[stack.size()-1];
                stack.pop_back();
                res.push_back(ptr->val);
                ptr=ptr->right;
            }
        }

        return res;
    }
};


//recursive
class Solution_recursive {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        
        return res;
    }
    
    void inorder(TreeNode *root) {
        if(root==NULL) return;
        preorder(root->left);
        res.push_back(root->val);
        preorder(root->right);
    }  
};

//iterative

int main(){


	return 0;
}