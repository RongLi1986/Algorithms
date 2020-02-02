# 21. Merge Two Sorted Lists

## Question link
(https://leetcode.com/problems/merge-two-sorted-lists/description/)

## Question Description
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

## 解题思路
time complexity : O(n)
space complexity : O(1)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

//iterate
class Solution {
public:
    ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) { 
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                tail->next = l2;
                break;
            }
            if(l2 == NULL){
                tail->next = l1;
                break;
            }
            
            ListNode* t;
            if(l1->val <= l2->val){
                t = l1;
                l1 = l1->next;
                
            }else{
                t = l2;
                l2 = l2->next;
            }
            
            tail->next = t;
            tail = t;
        }
        
        return dummy->next;
    }
};
```