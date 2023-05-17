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
    int pairSum(ListNode* head) {
        int nums[100000], n = -1, maximum = 0;

        while(head){
            nums[++n] = head->val;
            head = head->next;
        }

        for(int i = 0; i < n; i++, n--)
            maximum = max(nums[i] + nums[n], maximum);
            
        return maximum;
    }
};