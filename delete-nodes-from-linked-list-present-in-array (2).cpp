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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(), nums.end());
        ListNode* newHead = new ListNode();

        for(ListNode* curr = newHead; head; head = head->next){
            if(set.contains(head->val))
                continue;

            curr->next = new ListNode(head->val);
            curr = curr->next;
        }

        return newHead->next;
    }
};