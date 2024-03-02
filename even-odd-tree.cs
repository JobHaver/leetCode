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
    public bool IsEvenOddTree(TreeNode root) {
        Queue<TreeNode> row = new Queue<TreeNode>();
        bool odd = true;
        
        for(row.Enqueue(root); row.Count() != 0; odd = !odd){
            int size = row.Count();
            int prev = odd ? -1 : Int32.MaxValue;
            for(int i = 0; i++ < size; prev = row.Peek().val, row.Dequeue()){
                if(odd ? 
                   row.Peek().val <= prev || row.Peek().val % 2 == 0: 
                   row.Peek().val >= prev || row.Peek().val % 2 != 0)
                        return false;

                if(row.Peek().left != null)
                    row.Enqueue(row.Peek().left);
                if(row.Peek().right != null)
                    row.Enqueue(row.Peek().right);
            }
        }

        return true;
    }
}