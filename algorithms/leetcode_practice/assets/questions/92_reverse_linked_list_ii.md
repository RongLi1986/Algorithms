# 92. Reverse Linked List II

## Question link
(https://leetcode.com/problems/reverse-linked-list-ii/)

## Question Description
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

> Input: 1->2->3->4->5->NULL, m = 2, n = 4
> Output: 1->4->3->2->5->NULL

## 解题思路
Linkedlist

## Code
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Create Dumphead and find m node and n node.
        ListNode* d = new ListNode(0, head);
        ListNode* ptr = d;
        int c = 1;
        ListNode* t1;
        ListNode* h;
        ListNode* t;
        ListNode* h2;
        
        while(ptr != NULL){
            if(c == m) {
                t1 = ptr;
                h = ptr->next;
            }
            if(c == n + 1){
                t = ptr;
                h2 = ptr->next;
            }
            c++;
            ptr = ptr->next;
        }
        
        t1->next = NULL;
        t->next = NULL;
        
        // Reverse node from m to n 
        reverseList(h);
        
        // Reconnect list
        t1->next = t;
        h->next = h2;
        
        return d->next;
    }
    
    void reverseList(ListNode* head){
        ListNode* d = new ListNode(0);
        ListNode* ptr = head;
        
        while(ptr != NULL){
            ListNode* t = ptr;
            ptr = ptr->next;
            t->next = NULL;
            ListNode* t2 = d->next;
            d->next = t;
            t->next = t2;
        }
        
        return;
    }
};
```

## Time Complexity Analysis
Run time : O(n)
Space : O(1)