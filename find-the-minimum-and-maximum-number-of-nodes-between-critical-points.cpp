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
    vector<int> nodesBetweenCriticalPoints(ListNode* c) {
        int min = INT_MAX, prev = INT_MIN, first = INT_MIN;
        for(int i = 0; c && c->next && c->next->next; c = c->next, i++){
            if((c->val < c->next->val && c->next->val > c->next->next->val) || 
               (c->val > c->next->val && c->next->val < c->next->next->val)){
                if(prev >= 0)
                    min = std::min(min, i - prev);
                else
                    first = i;

                prev = i;
            }
        }

        if(min == INT_MAX)
            return {-1, -1};

        return {min, prev - first};
    }
};