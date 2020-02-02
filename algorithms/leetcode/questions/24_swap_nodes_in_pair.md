# 24 Swap Nodes in Pairs

## Question link
(https://leetcode.com/problems/swap-nodes-in-pairs/description/)

## Question Description
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.


Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

## 解题思路
Pop pair nodes from head (no swap if pop only one), and generate a new list.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head; //only one node case
        ListNode* tail = dummy;
        ListNode* ptr = head;
        
        while(ptr != NULL && ptr->next != NULL){
            ListNode* p = ptr;
            ListNode* n = ptr->next;
            
            ptr = n->next;
                
            n->next = p;
            p->next = ptr;
            
            tail->next = n;
            tail = tail->next->next;
        }
        
        return dummy->next;
    }
};
```