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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* curr, int val){
        val *= 10;
        val += curr->val;

        return !curr->left && !curr->right ? val : (curr->left ? helper(curr->left, val) : 0) + (curr->right ? helper(curr->right, val) : 0);
    }
};