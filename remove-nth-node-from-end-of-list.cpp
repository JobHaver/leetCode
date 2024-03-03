/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        for(ListNode *curr = head; curr; curr = curr->next)
            size++;
        
        if(size == 1 || !(size - n))
            return head->next;

        ListNode *prev = head, *curr = head->next;
        for(int i = 1, target = size - n; i < target; i++)
            prev = curr, curr = curr->next;
        
        prev->next = curr->next;

        return head;
    }
};