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
    int maxDif = 0;

public:
    int maxAncestorDiff(TreeNode* root) {
        helper(root, 0, INT_MAX);
        return maxDif;
    }

    void helper(TreeNode* root, int max, int min){
        if(!root)
            return;
        
        if(root->val < min)
            min = root->val;
        if(root->val > max)
            max = root->val;
        maxDif = std::max(maxDif, max-min);
        helper(root->left, max, min);
        helper(root->right, max, min);
    }
};