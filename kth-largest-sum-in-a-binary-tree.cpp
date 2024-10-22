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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> nodes({root});
        vector<long long> rows;

        while(nodes.size()){
            long long currRow = 0;
            for(int size = nodes.size(); size--; ){
                TreeNode* curr = nodes.front();
                nodes.pop();
                if(curr->left)
                    nodes.push(curr->left);
                if(curr->right)
                    nodes.push(curr->right);

                currRow += curr->val;
            }

            rows.push_back(currRow);
        }

        sort(rows.begin(), rows.end());

        return int(rows.size()) - k < 0 ? -1 : rows[rows.size()-k];
    }
};