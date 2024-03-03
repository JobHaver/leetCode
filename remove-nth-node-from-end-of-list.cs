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
        ListNode endFinder, curr, prev;
        for(endFinder = head; n-- > 0; endFinder = endFinder.next);
        
        for(prev = curr = head; endFinder != null; endFinder = endFinder.next){
            prev = curr;
            curr = curr.next;
        }

        if(prev == curr)
            return head.next;
        
        prev.next = curr.next;

        return head;
    }
}