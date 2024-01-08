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
    int high, low;
public:
    int rangeSumBST(TreeNode* root, int l, int h) {
        high = h, low = l;
        return helper(root);
    }

    int helper(TreeNode* root){
        if(!root)
            return 0;
        
        if(root->val < low)
            return helper(root->right);
        
        if(root->val > high)
            return helper(root->left);
        
        return root->val + helper(root->left) + helper(root->right);
    }
};