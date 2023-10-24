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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> row;

        row.push(root);
        while(row.size()){
            int rowSize = row.size(), max = row.front()->val;
            for(int i = 0; i < rowSize; i++, row.pop()){
                max = std::max(max, row.front()->val);
                if(row.front()->left) row.push(row.front()->left);
                if(row.front()->right) row.push(row.front()->right);
            }

            ans.push_back(max);
        }

        return ans;
    }
};