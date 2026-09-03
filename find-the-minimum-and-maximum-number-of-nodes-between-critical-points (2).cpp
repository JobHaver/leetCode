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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int criticalPointCount = 0, minDistance = INT_MAX, maxDistance = 0, prev;

        if(head){
            prev = head->val;
            head = head->next;
        }

        for(int index = 0, previousMin = 0, previousMax = INT_MAX; head && head->next; index++){
            if((prev < head->val && head->val > head->next->val) ||
               (prev > head->val && head->val < head->next->val)){
                if(++criticalPointCount >= 2){
                    minDistance = min(index - previousMin, minDistance);
                    maxDistance = index - previousMax;
                }

                previousMin = index;
                if(previousMax == INT_MAX)
                    previousMax = index;
            }

            prev = head->val;
            head = head->next;
        }

        if(criticalPointCount < 2)
            return {-1, -1};

        return {minDistance, maxDistance};
    }
};