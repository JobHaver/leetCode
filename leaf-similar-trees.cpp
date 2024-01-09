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
    vector<int> v;

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1);
        vector<int> v1 = v;
        v.clear();
        helper(root2);

        return v1 == v;
    }

    void helper(TreeNode* root){
        if(!root)
            return;
        
        if(!root->left && !root->right)
            v.push_back(root->val);
        else
            helper(root->left), helper(root->right);
    }
};