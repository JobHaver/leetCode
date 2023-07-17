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
private:
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr = head, *next;
        for(; curr; prev = curr, curr = next){
            next = curr->next;
            curr->next = prev;
        }

        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* curr = NULL;

        l1 = reverse(l1);
        l2 = reverse(l2);

        for(; l1 && l2; l1 = l1->next, l2 = l2->next, carry /= 10)
            curr = new ListNode((carry = carry + l1->val + l2->val) % 10, curr);

        for(; l1; l1 = l1->next, carry /= 10)
            curr = new ListNode((carry = carry + l1->val) % 10, curr);

        for(; l2; l2 = l2->next, carry /= 10)
            curr = new ListNode((carry = carry + l2->val) % 10, curr);

        if(carry)
            curr = new ListNode(1, curr);

        return curr ? curr : new ListNode(0);
    }
};