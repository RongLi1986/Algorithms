# 19. Remove Nth Node From End of List

## Question link
(https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

## Question Description
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

## 解题思路
In linkedlist question, dummy node is always useful.


```c++
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* dummy = new ListNode(0); // dummy node is always useful
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
```