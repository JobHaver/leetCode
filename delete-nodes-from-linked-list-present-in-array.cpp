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
        unordered_set<int> set;
        for(int n : nums)
            set.insert(n);

        for(ListNode *curr = head, *prev = NULL; curr; curr = curr->next){
            if(set.find(curr->val) != set.end()){
                if(curr == head)
                    head = curr->next;

                if(prev)
                    prev->next = curr->next;
            }
            else
                prev = curr;
        }

        return head;
    }
};