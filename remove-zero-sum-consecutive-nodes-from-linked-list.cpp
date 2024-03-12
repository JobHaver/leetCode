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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<pair<int, ListNode*>> sums;
        for(ListNode* curr = head; curr; curr = curr->next){
            sums.push_back({0, curr});
            for(int i = 0; i < sums.size(); i++)
                if(!(sums[i].first += curr->val))
                    sums.erase(sums.begin()+i, sums.end());
        }

        sums.push_back({0, NULL});
        for(int i = 1; i < sums.size(); i++)
            sums[i-1].second->next = sums[i].second;

        return sums[0].second;
    }
};