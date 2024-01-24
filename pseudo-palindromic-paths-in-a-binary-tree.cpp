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
    map<int, bool> isOdd;
    int countPal = 0;
    int oddCount = 0;

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return countPal;
    }

    void helper(TreeNode* node){
        if(!node)
            return;

        bool &isO = isOdd[node->val];
        if(isO) oddCount--; else oddCount++;
        isO = !isO;
    
        if(!node->left && !node->right){
            if(oddCount < 2)
                countPal++;
        }
        else{
            helper(node->left);
            helper(node->right);
        }

        if(isO) oddCount--; else oddCount++;
        isO = !isO;
    }
};