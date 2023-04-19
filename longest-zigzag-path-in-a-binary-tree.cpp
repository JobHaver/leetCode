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
    int largest;

    void helper(TreeNode* node, int zags, bool left){
        if(!node)
            return;

        if(zags > largest)
            largest = zags;
        
        zags++;
        helper(node->left, left ? 1 : zags, true);
        helper(node->right, left ? zags : 1, false);
    }

public:
    int longestZigZag(TreeNode* root) {
        largest = 0;
        helper(root->left, 1, true);
        helper(root->right, 1, false);
        return largest;
    }
};