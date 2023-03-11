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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        list.clear();

        if(!head)
            return NULL;

        while(head){
            list.push_back(head->val);
            head = head->next;
        }

        return helper(0, list.size()-1);
    }

private:
	vector<int> list;

    TreeNode* helper(int left, int right){
        int mid = (left + right) / 2;

        return new TreeNode(list[mid], mid==left ? NULL : helper(left, mid-1), mid==right ? NULL : helper(mid+1, right));
    }
};