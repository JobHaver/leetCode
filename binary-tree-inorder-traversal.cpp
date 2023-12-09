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
    vector<int> list;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return list;
    }

    void traversal(TreeNode* node){
        if(node){
            traversal(node->left);
            list.push_back(node->val);
            traversal(node->right);
        }
    }
};