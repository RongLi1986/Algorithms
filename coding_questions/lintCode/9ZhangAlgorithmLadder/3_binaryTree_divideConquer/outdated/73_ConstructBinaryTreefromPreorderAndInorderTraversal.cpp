/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Notice

You may assume that duplicates do not exist in the tree.

Example
Given in-order [1,2,3] and pre-order [2,1,3], return a tree:

  2
 / \
1   3
*/

/*
1.from preorder first one is root
2.find it from inorder, check whether left leaf and right leaf is exist.
3.recursive to do root's leaf nodes
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
private:
    int index;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        index=0;
        TreeNode* root = buildTreeRecursive(preorder,inorder,0,inorder.size());
        
        return root;
    }
    
    TreeNode* buildTreeRecursive(
        vector<int> &preorder, 
        //int index, 
        vector<int> &inorder, 
        int start, 
        int end
    )
    {
        
        if(index >= preorder.size() || start>=end){
            index--;
            return NULL;
        }
        
        TreeNode* tmp=new TreeNode(preorder[index]);
        
        int flag=INT_MAX;
        for(int i=start;i<end;i++){
            if(inorder[i]==preorder[index]){
                flag=i;
                break;
            }
        }
        
        //cout<<start<<" "<<end<<" "<<index<<" "<<preorder[index]<<" "<<flag<<endl;   
        
        if(flag==INT_MAX)
            return NULL;    
        
        //check availablity of left leaf and right leaf
        if(flag==inorder.size()-1){ //no right leaf
        //cout<<"ll"<<endl;
            index++;
            tmp->left=buildTreeRecursive(preorder,inorder,start,flag);
            tmp->right=NULL;
            
        }else if(flag==0){ //no left leaf
            index++;
        //cout<<"rr"<<endl;
            tmp->left =NULL;
            tmp->right = buildTreeRecursive(preorder,inorder,flag+1,end);
        }else{
        //cout<<"bb"<<endl;
            index++;
            tmp->left = buildTreeRecursive(preorder,inorder,start,flag);
            index++;
            tmp->right = buildTreeRecursive(preorder,inorder,flag+1,end);
        }
        
        return tmp;
    }
};

int main(){
	
	return 0;
}