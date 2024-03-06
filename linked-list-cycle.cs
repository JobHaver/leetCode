/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        for(ListNode fast = head, slow = head; fast != null && fast.next != null; fast = fast.next, slow = slow.next)
            if((fast = fast.next) == slow)
                return true;

        return false;
    }
}