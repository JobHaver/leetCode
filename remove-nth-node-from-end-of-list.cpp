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
        ListNode *endFinder, *curr, *prev;
        for(endFinder = head; n--; endFinder = endFinder->next);
        
        for(prev = curr = head; endFinder; endFinder = endFinder->next)
            prev = curr, curr = curr->next;

        if(prev == curr)
            return head->next;
        
        prev->next = curr->next;

        return head;
    }
};