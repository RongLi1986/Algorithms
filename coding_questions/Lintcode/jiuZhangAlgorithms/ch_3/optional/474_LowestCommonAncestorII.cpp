/*
Lowest Common Ancestor II

 Description
 Notes
 Testcase
 Judge
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Have you met this question in a real interview? Yes
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

/*
use hashmap keep parents
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        // Write your code here
        unordered_map<ParentTreeNode*, bool> hashmap;
        ParentTreeNode *ptr = A;
        
        while(ptr!=NULL){
            if(hashmap.find(ptr) == hashmap.end()){
                hashmap[ptr]=true;
            }
            ptr = ptr->parent; 
        }
        
        
        ptr = B;
        
        while(ptr!=NULL){
            if(hashmap.find(ptr) != hashmap.end()){
                return ptr;
            }
            ptr = ptr->parent;
        }
        
        return NULL;
    }
};

int main(){
	
	return 0;
}