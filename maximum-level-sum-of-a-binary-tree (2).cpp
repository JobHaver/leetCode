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
        int maxSum = INT_MIN, maxLevel = 0, currSum;

        nodes.push(root);
        for(int currLevel = 1; nodes.size(); currLevel++){
            currSum = 0;
            for(int size = nodes.size(), i = 0; i < size; i++){
                if(nodes.front()->left)
                    nodes.push(nodes.front()->left);

                if(nodes.front()->right)
                    nodes.push(nodes.front()->right);

                currSum += nodes.front()->val;
                nodes.pop();
            }

            if(currSum > maxSum){
                maxSum = currSum;
                maxLevel = currLevel;
            }
        }

        return maxLevel;
    }
};