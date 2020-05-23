# 61. Rotate List

## Question link
(https://leetcode.com/problems/rotate-list/description/)

## Question Description

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

## 解题思路

```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        if(k == 0) return head;
        
        int count = 0;
        int size = 1;
        ListNode* ptr = head;
        
        //find tail and length
        while(ptr->next!=NULL){
            ptr = ptr->next;
            size++;
        }
        
        //connect tail1 to head
        ptr->next = head;
        
        //make tail to cut point;
        ptr = head;
        size = size - (k % size);
        while(size > 1){
            ptr = ptr->next;
            size--;
        }
        
        //newhead and cut list
        ListNode* retNode = ptr->next;
        ptr->next = NULL;
        
        return retNode;
    }
};
```