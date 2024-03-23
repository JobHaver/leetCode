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
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *curr, *prev;
        for(curr = head, prev = NULL; curr; prev = curr, curr = next){
            next = curr->next;
            curr->next = prev;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode *fast, *slow;
        for(fast = slow = head; fast->next && fast->next->next; fast = fast->next->next, slow = slow->next);

        ListNode *l = head, *r = reverseList(slow->next), *tl, *tr;
        slow->next = NULL;
        while(r){
            tl = l->next;
            tr = r->next;
            l->next = r;
            r->next = tl;
            l = tl;
            r = tr;
        }
    }
};