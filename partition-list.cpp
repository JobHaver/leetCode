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
    ListNode* partition(ListNode* head, int x) {
        stack<ListNode*> less;
        stack<ListNode*> greater;

        for(ListNode* curr = head; curr; curr = curr->next){
            if(curr->val < x)
                less.push(curr);
            else
                greater.push(curr);
        }

        ListNode* prev = NULL;

        for(; !greater.empty(); prev = greater.top(), greater.pop())
            greater.top()->next = prev;

        for(; !less.empty(); prev = less.top(), less.pop())
            less.top()->next = prev;

        return prev;
    }
};