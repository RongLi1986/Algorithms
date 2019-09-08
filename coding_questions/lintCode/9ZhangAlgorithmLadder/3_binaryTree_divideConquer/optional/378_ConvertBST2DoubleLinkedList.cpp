/*
Convert Binary Search Tree to Doubly Linked List

Convert a binary search tree to doubly linked list with in-order traversal.

Have you met this question in a real interview? Yes
Example
Given a binary search tree:

    4
   / \
  2   5
 / \
1   3
return 1<->2<->3<->4<->5
*/


/*
dfs
*/


#include <iostream>
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */

class Solution {
private:
    vector<int> list;
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        bstDFS(root);
        DoublyListNode* head = NULL;
        DoublyListNode* tail = NULL;
        
        for(int i=0;i<list.size();i++){
            DoublyListNode* node=new DoublyListNode(list[i]);
            if(head==NULL){
                head=node;
                tail=node;
            }else{
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
        }
        
        return head;
    }
    
    void bstDFS(TreeNode* root){
        if(root==NULL)
            return;
            
        bstDFS(root->left);
        list.push_back(root->val);
        bstDFS(root->right);
        
        return;
    }
};