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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> row;
        TreeNode* curr;
        
        for(row.push(root); !row.empty();){
            curr = row.front();
            for(int size = row.size(), i = 0; i < size; i++, row.pop()){
                if(row.front()->left)
                    row.push(row.front()->left);
                if(row.front()->right)
                    row.push(row.front()->right);
            }
        }

        return curr->val;
    }
};