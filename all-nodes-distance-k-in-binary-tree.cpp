/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
    TreeNode *t;

    int finder(TreeNode* curr, int k){
        if(curr){
            if(curr == t){
                addNodes(curr, k);
                return k-1;
            }

            int l = finder(curr->left, k);
            int r = finder(curr->right, k);
            
            if(!l || !r)
                ans.push_back(curr->val);
            else if(l-- > 0){
                addNodes(curr->right, l);
                return l;
            }
            else if(r-- > 0){
                addNodes(curr->left, r);
                return r;
            }
        }

        return -1;
    }

    void addNodes(TreeNode* curr, int k){
        if(!curr || k < 0)
            return;
        
        if(!k--)
            ans.push_back(curr->val);

        addNodes(curr->left, k);
        addNodes(curr->right, k);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        t = target;
        finder(root, k);

        return ans;
    }
};