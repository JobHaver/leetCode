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
typedef pair<bool, TreeNode*> p;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, p> mp;

        for(vector<int> &v : descriptions){
            p &parent = mp[v[0]];
            p &child = mp[v[1]];

            if(!parent.second)
                parent.second = new TreeNode(v[0]);

            if(!child.second)
                child.second = new TreeNode(v[1]);

            child.first = true;
            if(v[2])
                parent.second->left = child.second;
            else
                parent.second->right = child.second;
        }

        for(auto &m : mp)
            if(!m.second.first)
                return m.second.second;

        return NULL;
    }
};