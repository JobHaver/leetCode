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
    ListNode* detectCycle(ListNode* head) {
        unordered_map<ListNode*, int> seen;
        ListNode* curr = head;

        while(curr){
            int& index = seen[curr];
            if(index++)
                return curr;

            curr = curr->next;
        }

        return NULL;
    }
};