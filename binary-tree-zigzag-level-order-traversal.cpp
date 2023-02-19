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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> nodes;
        int depth = 0;

        if(!root)
            return ans;
        
        nodes.push_back(root);

        while(!nodes.empty()){
            vector<TreeNode*> temp;
            vector<int> row;
            for(TreeNode* & node : nodes){
                row.push_back(node->val);
                if(node->left)
                    temp.push_back(node->left);
                if(node->right)
                    temp.push_back(node->right);
            }

            if(depth%2 != 0)
                reverse(row.begin(), row.end());

            ans.push_back(row);
            nodes = temp;
            depth++;
        }

        return ans;
    }
};