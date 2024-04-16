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
    int v;

    void helper(TreeNode* curr, int depth){
        if(!curr)
            return;

        if(!depth--){
            curr->left = new TreeNode(v, curr->left, NULL);
            curr->right = new TreeNode(v, NULL, curr->right);
            return;
        }

        helper(curr->left, depth);
        helper(curr->right, depth);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, NULL);
        
        v = val;
        helper(root, depth-2);
        return root;
    }
};