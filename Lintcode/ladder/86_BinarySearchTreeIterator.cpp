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
inorder DFS scan
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

    //inorder scan
    vector<TreeNode*> inorderTraversal(TreeNode *root) {
        // write your code here
        if(root==NULL) 
            return container;
        
        stack<TreeNode*> stk;
        TreeNode* ptr=root;

        do{
            //push ptr into stk
            //cout<<ptr->val<<endl;
            stk.push(ptr);
           
            if(ptr->left){ //left child is exist
                ptr=ptr->left;
                
            }else{ //no left child
                ptr=stk.top();
                container.push_back(ptr);
                stk.pop();
                
                if(!ptr->right){  //reach end
                    do{
                        //cout<<"val:"<<stk.top()->val<<endl;
                        if(stk.empty())
                            return container;
                            
                        ptr=stk.top();
                        container.push_back(ptr);
                        stk.pop();
                    }while(!ptr->right);
                }

                ptr=ptr->right;
            }
        }while(1);

        return container;
    }
};

int main(){
	
	return 0;
}