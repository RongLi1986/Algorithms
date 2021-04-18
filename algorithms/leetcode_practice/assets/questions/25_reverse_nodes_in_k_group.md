# 25 Reverse Nodes in k-Group

## Question link
(https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

## Question Description
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.


## 解题思路


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
    ListNode* reverseKGroup(ListNode *head, int k){
        ListNode* dummp = new ListNode(0); dummp->next = head;
        ListNode* tail =  dummp;
        
        ListNode* ptr =  head;
        while(ptr != NULL){
            //find list after k move;
            ListNode* tmp_head = ptr;
            ListNode* tmp_tail = ptr;
            int i = 1;
            while(i < k){
                tmp_tail = tmp_tail->next;
                //if nodes number is smaller than k, 
                //add to tail and return
                if(tmp_tail == NULL && i < k) {
                    tail->next = tmp_head;
                    return dummp->next;
                }
                i++;
            }
            ptr = tmp_tail->next;
            tmp_tail->next = NULL;
            
            //reverse the tmp list
            ListNode* p =  tmp_head;
            ListNode* d = new ListNode(0);
            while(p != NULL){
                ListNode* t = p->next;
                p->next = d->next;
                d->next = p;
                p = t;
            }
            
            //add reverse list to tail
            tail->next = d->next;
            tail = tmp_head;
        }
        
        return dummp->next;
    }
};
```