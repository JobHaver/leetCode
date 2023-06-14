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
    vector<int> easy;

    void helper(TreeNode* curr){
        if(curr->left)
            helper(curr->left);

        easy.push_back(curr->val);
        
        if(curr->right)
            helper(curr->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        easy.clear();
        helper(root);

        for(int i = 1; i < easy.size(); i++){
            if(easy[i] - easy[i-1] < diff)
                diff = easy[i] - easy[i-1];
        }

        return diff;
    }
};