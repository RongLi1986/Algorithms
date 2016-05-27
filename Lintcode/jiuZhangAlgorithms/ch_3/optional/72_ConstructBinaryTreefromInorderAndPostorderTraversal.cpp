/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Notice

You may assume that duplicates do not exist in the tree.

Given inorder [1,2,3] and postorder [1,3,2], return a tree:

  2
 / \
1   3
*/

/*
1.from postorder last one is root
2.find it from inorder, check whether right leaf and left leaf is exist.
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
private:
    int index;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        index=postorder.size()-1;
        TreeNode* root = buildTreeRecursive(postorder,inorder,0,inorder.size());
        
        return root;
    }
    
    TreeNode* buildTreeRecursive(
        vector<int> &postorder, 
        //int index, 
        vector<int> &inorder, 
        int start, 
        int end
    )
    {
        
        if(index <0 || start>=end){
            index++;
            return NULL;
        }
        
        TreeNode* tmp=new TreeNode(postorder[index]);
        
        int flag=INT_MAX;
        for(int i=start;i<end;i++){
            if(inorder[i]==postorder[index]){
                flag=i;
                break;
            }
        }
        
        //cout<<start<<" "<<end<<" "<<index<<" "<<preorder[index]<<" "<<flag<<endl;   
        
        if(flag==INT_MAX)
            return NULL;    
        
        //check availablity of left leaf and right leaf
        if(flag==0){ //no left leaf
            index--;
        //cout<<"rr"<<endl;
            tmp->left =NULL;
            tmp->right = buildTreeRecursive(postorder,inorder,flag+1,end);
        }else if(flag==inorder.size()-1){ //no right leaf
        //cout<<"ll"<<endl;
            index--;
            tmp->left=buildTreeRecursive(postorder,inorder,start,flag);
            tmp->right=NULL;
            
        }else{
        //cout<<"bb"<<endl;
            index--;
            tmp->right = buildTreeRecursive(postorder,inorder,flag+1,end);
            index--;
            tmp->left = buildTreeRecursive(postorder,inorder,start,flag);
        }
        
        return tmp;
    }
};

int main(){
	
	return 0;
}