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
    vector<TreeNode*> groves;
    unordered_map<int, bool> mp;

    bool helper(TreeNode* curr){
        bool result = false;

        if(!curr)
            return result;

        if(mp.find(curr->val) != mp.end()){
            if(curr->left && mp.find(curr->left->val) == mp.end())
                groves.push_back(curr->left);
            if(curr->right && mp.find(curr->right->val) == mp.end())
                groves.push_back(curr->right);

            result = true;
        }

        if(helper(curr->left))
            curr->left = NULL;
        if(helper(curr->right))
            curr->right = NULL;

        return result;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i : to_delete)
            mp[i] = true;

        if(root && mp.find(root->val) == mp.end())
            groves.push_back(root);

        helper(root);

        return groves;
    }
};