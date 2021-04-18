# 82. Remove Duplicates from Sorted List II

## Question link
(https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)

## Question Description

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* dumpHead = new ListNode(0);
        
        dumpHead->next = head;
        ListNode* pre = dumpHead;
        ListNode* cur = head;
        while(cur != NULL){
            while(cur->next != NULL && cur->val == cur->next->val){
                cur = cur->next;
            }
            if(pre->next == cur){
                pre = pre->next;
            }else{
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dumpHead->next;
    }
};
```