/*
Flatten Binary Tree to Linked List 
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 */

/*
solution:
1.make node's left leap and right leap flat
2.disconnect node's right. connect node's left to right
2.connect right to left  end.
*/

#include <iostream>
#include <vector>
using namespace std;


//Definition for binary tree
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        //return 
        if(root==nullptr)
            return;

        //case1
        if(root->left!=nullptr&&root->right!=nullptr){
            //make root's left and right leap flat
            TreeNode* leftNode=root->left;
            flatten(leftNode);
            TreeNode* rightNode=root->right;
            flatten(rightNode);
            
            //move left to right, save old right
            root->left=nullptr;
            root->right=leftNode;

            //find left (new right) tail and link with old right
            TreeNode* ptr=leftNode;
            while(ptr->right!=nullptr)
                ptr=ptr->right;

            ptr->right=rightNode;

        //case2
        }else if(root->left!=nullptr&&root->right==nullptr){
            TreeNode* leftNode=root->left;
            flatten(leftNode);
            root->left=nullptr;            
            root->right=leftNode;
        
        //case3
        }else if(root->left==nullptr&&root->right!=nullptr){
            TreeNode* rightNode=root->right;
            flatten(rightNode);
        }else
            return;
    }
};

int main(){

    TreeNode* root=new TreeNode(0);
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    
    a->left=b;
    a->right=c;
    
    root->left=a;
    root->right=d;
    d->left=e;
    


	Solution s;
    s.flatten(root);

    TreeNode* ptr=root;

	while(ptr!=nullptr){
        cout<<ptr->val<<"->";
        ptr=ptr->right;
    }
    cout<<endl;


	return 0;
}