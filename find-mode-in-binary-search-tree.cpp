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
    unordered_map<int, int> count;

    void helper(TreeNode* curr){
        if(!curr)
            return;
        
        count[curr->val]++;
        helper(curr->left);
        helper(curr->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        helper(root);

        int max = -1;
        for(pair<const int, int> &p : count)
            if(p.second > max) max = p.second;
        
        vector<int> ans;
        for(pair<const int, int> &p : count)
            if(p.second == max) ans.push_back(p.first);

        return ans;
    }
};