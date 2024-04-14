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
    int ans;

    void helper(TreeNode* node, bool left){
        if(!node)
            return;
        
        if(left && !node->left && !node->right){
            ans += node->val;
            return;
        }
            
        helper(node->left, true);
        helper(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        
        helper(root, false);

        return ans;
    }
};