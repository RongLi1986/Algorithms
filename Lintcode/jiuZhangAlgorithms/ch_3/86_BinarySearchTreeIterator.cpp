/*
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.


For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]

   10
 /    \
1      11
 \       \
  6       12

*/

/*
inorder DFS scan, and keep result into a queue
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        
        //initial container
        inorderTraversal(root);
        i=0;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return i < container.size();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        return container[i++];
    }
    
private:
    vector<TreeNode*> container;
    int i;

    //inorder dfs non-recursive
    vector<TreeNode*> inorderTraversal(TreeNode *root) {
        // write your code here
        if(root == NULL) 
            return container;
        
        stack<TreeNode*> stk;
        TreeNode* ptr = root;

        //stk.push(ptr);
        
        while(!stk.empty() || ptr != NULL){
            if(ptr != NULL){
                stk.push(ptr);
                ptr = ptr->left;
            }else{
                 ptr=stk.top();
                 container.push_back(ptr);
                 stk.pop();
                 
                 ptr=ptr->right;
            }
        
        }

        return container;
    }
};

int main(){
	
	return 0;
}