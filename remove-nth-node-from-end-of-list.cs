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
        ListNode endFinder, prev;
        for(endFinder = head; n-- > 0; endFinder = endFinder.next);

        if(endFinder == null)
            return head.next;
        
        for(prev = head, endFinder = endFinder.next; endFinder != null; endFinder = endFinder.next)
            prev = prev.next;

        prev.next = prev.next.next;

        return head;
    }
}