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
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        int diff = INT_MAX;
        helper(root, nodes);
        sort(nodes.begin(), nodes.end());

        //cout << endl;
        // for(auto i : nodes)
        //     cout << i << " ";
        
        for(int i=0; i < nodes.size()-1; i++){
            if(nodes[i+1]-nodes[i] < diff)
                diff = nodes[i+1]-nodes[i];
        }

        return diff;
    }

    void helper(TreeNode* node, vector<int>& nodes){
        nodes.push_back(node->val);
        //cout << node->val << " ";

        if(node->left)
            helper(node->left, nodes);

        if(node->right)
            helper(node->right, nodes);
    }
};