
 /* Definition for a binary tree node.*/
  public class TreeNode {
      public int val;
      public TreeNode left;
      public TreeNode right;
      public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
 public class Solution {
    public int MinDepth(TreeNode root) {
        if(root == null) return 0;
        if (root.left == null) return 1 + MinDepth(root.right);
        if (root.right == null) return 1 + MinDepth(root.left);
        // If both children are present, return the minimum depth
        int depthL = 1 + MinDepth(root.left);
        int depthR = 1 + MinDepth(root.right);
        return Math.Min(depthL, depthR);
    }
}