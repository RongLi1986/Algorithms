/*
Construct Binary Tree from Preorder and Inorder Traversal 
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/

/*
steps:
1. mark the first element of the preorder as root element
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()) return NULL;
        TreeNode* root=NULL;
        preStart=0;
        root=buildTreeRescrusive(preorder,inorder,0,inorder.size());
        return root;
    }
    
    TreeNode* buildTreeRescrusive(vector<int>& preorder, vector<int>& inorder,int inStart, int inEnd){
        if(inStart>=inEnd) {
            preStart--;
            return NULL;
        }
        int cutIndex=-1;
        
        //create node
        TreeNode* node=new TreeNode(preorder[preStart]);
        
        //find the node
        for(int i=inStart;i<inEnd;i++){
            if(preorder[preStart]==inorder[i]){
                cutIndex=i;
            }
        }
        
        //no left
        if(cutIndex==inStart){
            preStart++;
            node->left=NULL;
            node->right=buildTreeRescrusive(preorder,inorder,cutIndex+1,inEnd);
        }
        //no right
        else if(cutIndex==inEnd-1){
            preStart++;
            node->left=buildTreeRescrusive(preorder,inorder,inStart,cutIndex);
            node->right=NULL;
        }
        //normal case
        else{
            preStart++;
            node->left=buildTreeRescrusive(preorder,inorder,inStart,cutIndex);
            preStart++;
            node->right=buildTreeRescrusive(preorder,inorder,cutIndex+1,inEnd);
        }
        
        return node;
    }
};



class Solution_old {
private:
    int size;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        size=preorder.size();
        
        return buildTreeRecrusive(inorder,preorder,0,size-1);
    }

    TreeNode* buildTreeRecrusive(vector<int> &inorder, vector<int> &preorder, int startIndex, int endIndex){
        
        if(preorder.size()==0) return NULL;

        if(startIndex>endIndex) return NULL;
        cout<<"preorder before: "<<preorder.size()<<endl;
        
        TreeNode* root=new TreeNode(preorder[0]);
        
        for(int i=startIndex;i<endIndex+1;i++){
          if(inorder[i]==preorder[0]){
            cout<<i<<endl;
            preorder.erase(preorder.begin());//delete first element
            cout<<"preorder end: "<<preorder.size()<<endl;
            root->left= buildTreeRecrusive(inorder,preorder,startIndex,i-1);
            root->right=buildTreeRecrusive(inorder,preorder,i+1,endIndex);
            break;
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
  vector<int> preorder={0,1,3,4,2,5,6};
	Solution s;

  TreeNode* root=s.buildTree(preorder, inorder);

  printTree(root);

	return 0;
}