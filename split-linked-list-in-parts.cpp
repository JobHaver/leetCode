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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int listSize = 0;

        for(ListNode *temp = head; temp; temp = temp->next)
            listSize++;

        int partSize = listSize / k, remainder = listSize % k;
        for(ListNode *curr = head, *prev = NULL; k; k--){
            ans.push_back(curr);
            for(int i = 0; i < partSize; i++)
                prev = curr, curr = curr->next;

            if(remainder-- > 0)
                prev = curr, curr = curr->next;
            
            if(prev)
                prev->next = NULL;
        }

        return ans;
    }
};