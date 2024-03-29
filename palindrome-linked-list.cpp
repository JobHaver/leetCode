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
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        for(ListNode* curr = head; curr; curr = curr->next)
            list.push_back(curr->val);

        for(int l = 0, r = list.size()-1; l < r;)
            if(list[l++] != list[r--])
                return false;

        return true;
    }
};