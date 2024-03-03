/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        int size = 0;
        for(ListNode c = head; c != null; c = c.next)
            size++;
        
        if(size == 1 || (size - n) == 0)
            return head.next;

        ListNode prev = head, curr = head.next;
        for(int i = 1, target = size - n; i < target; i++){
            prev = curr;
            curr = curr.next;
        }
        
        prev.next = curr.next;

        return head; 
    }
}