/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 
and x is a key of given BST. 
Return all the keys in ascending order.

If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].

    20
   /  \
  8   22
 / \
4   12
*/

/*
dfs: compare each node's value. 
if it smaller than range, only go right
if it larger than range, only go left.
otherwise go left and right.
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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        //cout<<"ss"<<endl;
        searchRangeRecursive(root,k1,k2,res);
        //cout<<"end"<<endl;
        sort(res.begin(), res.end());
        
        return res;
    }
    
    void searchRangeRecursive(TreeNode* root, int k1, int k2, vector<int>& res){
        if(root==NULL)
            return;
            
        if(root->val < k1 ){
            searchRangeRecursive(root->right, k1,k2,res);
        }else if(root->val > k2){
            searchRangeRecursive(root->left, k1,k2,res);
        }else{
            res.push_back(root->val);
            searchRangeRecursive(root->left, k1,k2,res);
            searchRangeRecursive(root->right, k1,k2,res);
        }    
    }
};

int main(){
	
	return 0;
}