/*
Recover Binary Search Tree Total Accepted: 32376 Total Submissions: 132009 My Submissions Question Solution 
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
use dfs put tree in list, and find swap node in list
then set it back to this tree.

it cost O(n) space

TODO: for constant space, maybe it could find swap value from tree directly.
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
vector<int> list;
public:
    void recoverTree(TreeNode* root) {
        int first=-1;
        int last=-1;
        int count=0;
        DFS(root);
        
        if(!list.empty()){
            for(int i=0;i<list.size()-1;i++){
                if(list[i]>list[i+1]){
                    if(count==0){
                        first=list[i];
                        last=list[i+1];
                        count++;
                    }else{
                        last=list[i+1];
                    }
                }
            }
            
            //have found swap val
            if(first!=-1&&last!=-1)
                changeVal(root,first,last);
        }
        return;
    }
    
    void DFS(TreeNode* root){
        if(root==NULL)
            return;
        
        DFS(root->left);
        list.push_back(root->val);
        DFS(root->right);
        
        return;
    }
    
    
    void changeVal(TreeNode* root, int first, int last){
        if(root==NULL) return;
        
        if(root->val==first){
            root->val=last;
        }else if(root->val==last){
            root->val=first;
        }
        
        changeVal(root->left,first,last);
        changeVal(root->right,first,last);
        
        
        return;
    }
    
};





 //space O(n) TODO:need to figure out how to sol this by constant space
class Solution_old {
private:
  vector<int> valList;
public:
    void recoverTree(TreeNode* root) {
          inorderGet(root);
          sort(valList.begin(),valList.end());
          reverse(valList.begin(),valList.end());
          inorderSet(root);
    }

    void inorderGet(TreeNode* root){
        if(root==NULL) return;
        
        inorderGet(root->left);
        valList.push_back(root->val);
        inorderGet(root->right);
        return;
    }

    void inorderSet(TreeNode* root){
        if(root==NULL) return;
        
        inorderSet(root->left);
        root->val=valList.back();
        valList.pop_back();
        inorderSet(root->right);
        return;
    }

};

int main(){

    return 0;
}