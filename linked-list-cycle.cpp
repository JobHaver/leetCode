/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for(ListNode *fast = head, *slow = head; fast && fast->next; fast = fast->next, slow = slow->next){
            if((fast = fast->next) == slow)
                return true;
        }

        return false;
    }
};