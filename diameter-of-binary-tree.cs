/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int max;

    private int Helper(TreeNode node){
        if(node == null)
            return 0;
        
        int left = Helper(node.left);
        int right = Helper(node.right);

        if(left + right > max)
            max = left + right;

        return Math.Max(left, right) + 1;
    }

    public int DiameterOfBinaryTree(TreeNode root) {
        max = 0;
        Helper(root);
        return max;
    }
}