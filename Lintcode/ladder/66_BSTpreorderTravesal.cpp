/*
Given a binary tree, return the preorder traversal of its nodes' values.
 */


/*
recursive solution
non-recursive solution
 */


#include <iostream>
using namespace std;

//recursive
class Solution {
private: 
    vector<int> res;
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        preorderTraversalRecursive(root);
        
        return res;
    }
    
    void preorderTraversalRecursive(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        res.push_back(root->val);
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
        
        return;
    }
};


//non recursive
class Solution{
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> stk;

        TreeNode* ptr=root;

        do{
            //push ptr into stk
            //cout<<ptr->val<<endl;
            res.push_back(ptr->val);
            stk.push(ptr);
           
            if(ptr->left){ //left child is exist
                ptr=ptr->left;
            }else{ //no left child
                if(!ptr->right){  //reach end
                    do{
                        //cout<<"val:"<<stk.top()->val<<endl;
                        stk.pop();
                        if(stk.empty())
                            return res;
                        ptr=stk.top();
                    }while(!ptr->right);
                }
                stk.pop();
                ptr=ptr->right;
            }
        }while(1);

        return res;
    }
};

int main(){

	return 0;
}