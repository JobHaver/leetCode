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
struct subtreeDepth{
    TreeNode* head;
    int depth;
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return subtreeFinder(root, 1).head;
    }

private:
    subtreeDepth subtreeFinder(TreeNode* curr, int depth){
        if(!curr)
            return {NULL, 0};

        subtreeDepth left = subtreeFinder(curr->left, depth+1);
        subtreeDepth right = subtreeFinder(curr->right, depth+1);

        if(left.depth == right.depth)
            return {curr, max(left.depth, depth)};
        else if(left.depth > right.depth)
            return left;
        else
            return right;
    }
};