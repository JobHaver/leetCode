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
    int ans = 0;

    pair<int, int> helper(TreeNode* curr){
        if(!curr)
            return {0, 0};
        
        pair<int, int> l = helper(curr->left);
        pair<int, int> r = helper(curr->right);
        pair<int, int> c = {1 + l.first + r.first, curr->val + l.second + r.second};
        if(c.second / c.first == curr->val) 
            ans++;

        return c;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);

        return ans;
    }
};