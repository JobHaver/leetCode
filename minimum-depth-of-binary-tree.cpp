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
    int helper(TreeNode* curr, int depth){
        if(!curr)
            return INT_MAX;

        if(!curr->left && !curr->right)
            return depth;
        
        return min(helper(curr->left, depth+1), helper(curr->right, depth+1));
    }

public:
    int minDepth(TreeNode* root) {
        return root ? helper(root, 1) : 0;
    }
};