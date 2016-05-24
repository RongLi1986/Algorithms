/*
Check a binary tree is completed or not. A complete binary tree is a binary tree that every level is completed filled except the deepest level. In the deepest level, all nodes must be as left as possible. See more definition

Have you met this question in a real interview? Yes
Example
    1
   / \
  2   3
 /
4
is a complete binary.

    1
   / \
  2   3
   \
    4
is not a complete binary.
*/

/*
bfs
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
private:
    deque<TreeNode*> queue;
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) {
        // Write your code here
        if(root == NULL)
            return true;
        
        queue.push_back(root);
        
        //flag==1 means right leaf is NULL, and  should not push any new node into queue
        int flag=0; 
        while(!queue.empty()){
            TreeNode* tmp = queue.front();
            queue.pop_front();
            if(tmp->left!=NULL&&tmp->right!=NULL){
                if(flag==1)
                    return false;
                queue.push_back(tmp->left);
                queue.push_back(tmp->right);
            }else if(tmp->left==NULL && tmp->right!=NULL){
                return false;
            }else if(tmp->left!=NULL && tmp->right==NULL){
                if(flag==1)
                    return false;
                queue.push_back(tmp->left);
                flag=1;
            }else{
                //all empty;
            }
        }
        
        return true;
    }
};

int main(){
	
	return 0;
}