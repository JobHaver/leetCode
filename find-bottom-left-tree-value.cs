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
    public int FindBottomLeftValue(TreeNode root) {
        Queue<TreeNode> row = new Queue<TreeNode>();
        TreeNode curr = null;
        
        for(row.Enqueue(root); row.Count() != 0;){
            curr = row.Peek();
            for(int size = row.Count(), i = 0; i < size; i++, row.Dequeue()){
                if(row.Peek().left != null)
                    row.Enqueue(row.Peek().left);
                if(row.Peek().right != null)
                    row.Enqueue(row.Peek().right);
            }
        }

        return curr.val;
    }
}