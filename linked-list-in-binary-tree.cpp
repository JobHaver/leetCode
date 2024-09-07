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
private:
    ListNode* head;

    bool check(ListNode* currList, TreeNode* currTree){
        if(!currList)
            return true;
        if(!currTree || currList->val != currTree->val)
            return false;
        
        return check(currList->next, currTree->left) || check(currList->next, currTree->right);
    }

    bool dfs(TreeNode* currTree){
        if(!currTree)
            return false;

        return dfs(currTree->left) || dfs(currTree->right) || 
            (head->val == currTree->val ?
            check(head->next, currTree->left) || check(head->next, currTree->right) :
            false);
    }

public:
    bool isSubPath(ListNode* h, TreeNode* r) {
        head = h;
        return dfs(r);
    }
};