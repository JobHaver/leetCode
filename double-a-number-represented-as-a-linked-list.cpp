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
    //bool return is carry
    bool helper(ListNode* curr){
        if(!curr)
            return false;

        int val = (curr->val * 2) + helper(curr->next);
        curr->val = val % 10;
        
        return val > 9;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        return helper(head) ? new ListNode(1, head) : head;
    }
};