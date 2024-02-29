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
    int isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> row;
        bool odd = true;
        
        for(row.push(root); !row.empty(); odd = !odd){
            int size = row.size();
            int prev = odd ? -1 : INT_MAX;
            for(int i = 0; i++ < size; prev = row.front()->val, row.pop()){
                if(odd ? 
                   row.front()->val <= prev || !(row.front()->val % 2) : 
                   row.front()->val >= prev || row.front()->val % 2)
                        return false;

                if(row.front()->left)
                    row.push(row.front()->left);
                if(row.front()->right)
                    row.push(row.front()->right);
            }
        }

        return true;
    }
};