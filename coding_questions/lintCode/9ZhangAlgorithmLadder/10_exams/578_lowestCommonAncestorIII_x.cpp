/*
Lowest Common Ancestor III

Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
*/

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
    /**ß
     * @param root: The root of the binary tree.
     * @param A and B: two nodes
     * @return: Return the LCA of the two nodes.
     */
    TreeNode *lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        // write your code here
        return findLCA(root, A->val, B->val);
    }
    
    // Finds the path from root node to given root of the tree, Stores the
    // path in a vector path[], returns true if path exists otherwise false
    bool findPath(TreeNode *root, vector<TreeNode*> &path, int k)
    {
        // base case
        if (root == NULL) return false;
     
        //cout<<root->val<<endl;
        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root);
     
        // See if the k is same as root's key
        if (root->val == k)
            return true;
     
        // Check if k is found in left or right sub-tree
        if ( (findPath(root->left, path, k)) || (findPath(root->right, path, k)) )
            return true;
     
        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
        return false;
    }
     
    // Returns LCA if node n1, n2 are present in the given binary tree,
    // otherwise return -1
    TreeNode* findLCA(TreeNode *root, int n1, int n2)
    {
        // to store paths to n1 and n2 from the root
        vector<TreeNode*> path1, path2;
     
        // Find paths from root to n1 and root to n1. If either n1 or n2
        // is not present, return -1
        if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
              return NULL;
        //cout<<"hh"<<endl;
        /* Compare the paths to get the first different value */
        int i;
        for (i = 0; i < path1.size() && i < path2.size() ; i++)
            if (path1[i]->val != path2[i]->val)
                break;
        return path1[i-1];
    }
};