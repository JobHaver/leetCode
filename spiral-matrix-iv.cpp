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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        for(int x = -1, y = -1, diff = 0, curr; head;){
            for(y++, x++, curr = n - diff; head && x < curr; x++, head = head->next)
                ans[y][x] = head->val;

            for(x--, y++, curr = m - diff; head && y < curr; y++, head = head->next)
                ans[y][x] = head->val;

            for(y--, x--, curr = -1 + diff; head && x > curr; x--, head = head->next)
                ans[y][x] = head->val;

            for(x++, y--, curr = -1 + ++diff; head && y > curr; y--, head = head->next)
                ans[y][x] = head->val;
        }

        return ans;
    }
};