# 86. Partition List

## Question link
(https://leetcode.com/problems/partition-list/)

## Question Description
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

![Image](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

Example 1:

> Input: head = [1,4,3,2,5,2], x = 3
> Output: [1,2,2,4,3,5]

Example 2:

> Input: head = [2,1], x = 2
> Output: [1,2]
 
Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

## 解题思路
linkedlist

## Code
```c++
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* node1 = new ListNode(0);
        ListNode* node2 = new ListNode(0);
        ListNode* p1 = node1; 
        ListNode* p2 = node2;

        while (head != NULL) {
            if (head->val < x)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }

        p2->next = NULL;
        p1->next = node2->next;
        return node1->next;
    }
};
```