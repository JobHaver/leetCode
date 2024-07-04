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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *start = new ListNode(), *curr = start;
        for(int sum = 0; head; head = head->next){
            if(head->val)
                sum += head->val;
            else{
                if(sum){
                    curr->next = new ListNode(sum);
                    curr = curr->next;
                }

                sum = 0;
            }
        }

        return start->next;
    }
};