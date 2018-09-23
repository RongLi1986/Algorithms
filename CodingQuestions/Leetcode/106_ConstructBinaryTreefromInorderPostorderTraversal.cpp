/*
Construct Binary Tree from Inorder and Postorder Traversal Total Accepted: 29158 Total Submissions: 109030 My Submissions Question Solution 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/*
step
1. mark the last element of the postorder as root element
2. find the the root element in inorder
3. it will divide the inorder into left and right
4. draw it
5. repeat the step until get binary tree
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
private:
    int preStart;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()||inorder.empty()) return NULL;
        TreeNode* root=NULL;
        preStart=postorder.size()-1;
        root=buildTreeRescrusive(postorder,inorder,0,inorder.size());
        return root;
    }
    
    TreeNode* buildTreeRescrusive(vector<int>& postorder, vector<int>& inorder,int inStart, int inEnd){
        if(inStart>=inEnd) {
            preStart++;
            return NULL;
        }
        int cutIndex=-1;
        
        //create node
        TreeNode* node=new TreeNode(postorder[preStart]);
        
        //find the node
        for(int i=inStart;i<inEnd;i++){
            if(postorder[preStart]==inorder[i]){
                cutIndex=i;
            }
        }
        
        //no left
        if(cutIndex==inStart){
            preStart--;
            node->left=NULL;
            node->right=buildTreeRescrusive(postorder,inorder,cutIndex+1,inEnd);
        }
        //no right
        else if(cutIndex==inEnd-1){
            preStart--;
            node->left=buildTreeRescrusive(postorder,inorder,inStart,cutIndex);
            node->right=NULL;
        }
        //normal case
        else{
            preStart--;
            node->right=buildTreeRescrusive(postorder,inorder,cutIndex+1,inEnd);
            preStart--;
            node->left=buildTreeRescrusive(postorder,inorder,inStart,cutIndex);
        }
        
        return node;
    }
};

class Solution_old {
private:
    int size;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        size=postorder.size();
        
        return buildTreeRecrusive(inorder,postorder,0,size-1);
    }

    TreeNode* buildTreeRecrusive(vector<int> &inorder, vector<int> &postorder, int startIndex, int endIndex){
        
        if(postorder.empty()) return NULL;

        if(startIndex>endIndex) return NULL;

        int lastIndex=postorder.size();
        TreeNode* root=new TreeNode(postorder[lastIndex-1]);
        
        for(int i=startIndex;i<endIndex+1;i++){
          if(inorder[i]==postorder[lastIndex-1]){
            postorder.pop_back();//delete last element
            root->right=buildTreeRecrusive(inorder,postorder,i+1,endIndex);
            root->left= buildTreeRecrusive(inorder,postorder,startIndex,i-1);
          }
        }
       
        return root;
    }
};

void printTree(TreeNode* root){
    if(root==NULL) return;
    TreeNode* node=root;
    cout<<node->val<<endl;
    printTree(node->left);
    printTree(node->right);

}


int main(){
  vector<int> inorder={3,1,4,0,5,2,6};
  vector<int> postorder={3,4,1,5,6,2,0};
	Solution s;

  TreeNode* root=s.buildTree(inorder,postorder);

  printTree(root);

	return 0;
}