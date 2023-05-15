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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr, *tail, *first;
        int i = 1;
        curr = head;

        while(i++ != k)
            curr = curr->next;

        first = curr;
        tail = head;
        curr = curr->next;
        
        while(curr){
            curr = curr->next;
            tail = tail->next;
        }

        swap(first->val,tail->val);

        return head;
    }
};