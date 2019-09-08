/*
Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example
Given 1->3->2->null, sort it to 1->2->3->null.
*/

/*
merge sort
*/

/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    public ListNode sortList(ListNode head) {
        if(head == null|| head.next == null)
            return head;
        ListNode slow = head, fast = head, firsthalf = head;
        while(fast.next!=null&&fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode secondhalf = slow.next;
        slow.next = null;
        
        ListNode leftlist = null, rightlist =null;
        if(firsthalf!=secondhalf){
            leftlist = sortList(firsthalf);
            rightlist = sortList(secondhalf);
        }
        return mergeTwoLists(leftlist, rightlist);
    }
    
    public ListNode mergeTwoLists(ListNode leftlist, ListNode rightlist){
        if(rightlist == null)
            return leftlist;
        if(leftlist == null)
            return rightlist;
        
        ListNode fakehead = new ListNode(-1);
        ListNode ptr = fakehead;
        while(rightlist!=null&&leftlist!=null){
            if(rightlist.val<leftlist.val){
                ptr.next = rightlist;
                ptr = ptr.next;
                rightlist = rightlist.next;
            }else{
                ptr.next = leftlist;
                ptr = ptr.next;
                leftlist = leftlist.next;
            }
        }
        
        if(rightlist!=null)
            ptr.next = rightlist;
        if(leftlist!=null)
            ptr.next = leftlist;
        
        return fakehead.next;
    }
}
