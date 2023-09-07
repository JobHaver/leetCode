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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head;
        int i = 1;
        stack<int> s;

        for(; temp && i != left; temp = temp->next, i++){}

        for(ListNode *t = temp; t && i++ <= right; t = t->next)
            s.push(t->val);
        
        for(; temp && !s.empty(); temp = temp->next, s.pop())
            temp->val = s.top();

        return head;
    }
};