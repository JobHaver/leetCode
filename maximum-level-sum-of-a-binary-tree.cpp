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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int max = INT_MIN, row = 1, ans = 1;

        while(!nodes.empty()){
            int rowSize = nodes.size(), total = 0;
            for(int i = 0; i < rowSize; i++){
                TreeNode* temp = nodes.front();
                nodes.pop();

                if(temp->left)
                    nodes.push(temp->left);
                if(temp->right)
                    nodes.push(temp->right);
                
                total += temp->val;
            }

            if(total > max){
                max = total;
                ans = row;
            }

            row++;
        }

        return ans;
    }
};