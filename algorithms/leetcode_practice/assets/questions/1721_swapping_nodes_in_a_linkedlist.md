# 1721. Swapping Nodes in a Linked List

## Question link
(https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

## Question Description

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

Example 3:

Input: head = [1], k = 1
Output: [1]

Example 4:

Input: head = [1,2], k = 1
Output: [2,1]

Example 5:
Input: head = [1,2,3], k = 2
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100

##
Linkedlist

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {        
        ListNode* dumpNode = new ListNode(INT_MAX, head);
        ListNode* ptr = dumpNode;

        int i = 1;
        while(i < k){
            ptr = ptr->next;;
            i++;
        }
        
        ListNode* s = ptr;
        ListNode* n = ptr->next;
        ptr = dumpNode;
        
        while(n->next != NULL){
            ptr = ptr->next;
            n = n->next;
        }
        
        ListNode* t = ptr;
        // cout<<s->val<<" "<<t->val<<endl;    
        swap(s, t);
        
        return dumpNode->next;
    }
        
    void swap(ListNode* src, ListNode* tgt){
        //drop
        ListNode* a = src->next;  
        ListNode* t1 = a->next;   
        
        ListNode* b = tgt->next;  
        ListNode* t2 = b->next;  
        
        
        //connect
        src->next = b;
        b->next = t1;
        
        tgt->next = a;
        a->next = t2;
        
        //corner case : swap adjacent nodes
        if(b == t1) b->next = a;  
        if(a == t2) a->next = b;
        return;
    }
};
```