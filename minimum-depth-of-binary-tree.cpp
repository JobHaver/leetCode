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
    int minDepth(TreeNode* root) {
        if(!root) 
            return 0;

        queue<TreeNode*> row;
        row.push(root);
        int ans = 0;

        while(!row.empty()){
            ans++;
            for(int rowSize = row.size(); rowSize--;){
                TreeNode* curr = row.front();
                row.pop();
                if(!curr->left && !curr->right)
                    return ans;
                if(curr->left)
                    row.push(curr->left);
                if(curr->right)
                    row.push(curr->right);
            }
        }

        return ans;
    }
};