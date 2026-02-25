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
public:
    int sumRootToLeaf(TreeNode* root) {
        return binaryNumberConverter(root, 0, 0);
    }

    int binaryNumberConverter(TreeNode* curr, int depth, int currAmmount){
        if(!curr)
            return 0;

        currAmmount *= 2;

        if(curr->val)
            currAmmount += 1;

        if(!curr->left && !curr->right)
            return currAmmount;

        return 
            binaryNumberConverter(curr->left, depth + 1, currAmmount) + 
            binaryNumberConverter(curr->right, depth + 1, currAmmount);
    }
};