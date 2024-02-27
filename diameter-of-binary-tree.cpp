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
    int max;

    int helper(TreeNode* node){
        if(!node)
            return 0;
        
        int left = helper(node->left);
        int right = helper(node->right);

        if(left + right > max)
            max = left + right;

        return std::max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max = 0;
        helper(root);
        return max;
    }
};