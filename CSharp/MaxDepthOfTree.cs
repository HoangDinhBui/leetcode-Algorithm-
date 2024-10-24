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
public class Solution23 {
    public int MaxDepth(TreeNode root) {
        if(root == null) return 0;
        
        int depthL = MaxDepth(root.left);
        int depthR = MaxDepth(root.right);
        
        return Math.Max(depthL, depthR) + 1;
    }
}