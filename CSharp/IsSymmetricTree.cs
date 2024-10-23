/**
 Definition for a binary tree node.*/
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution22
{
    public bool IsMirror(TreeNode root1, TreeNode root2)
    {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        return (root1.val == root2.val)
        && IsMirror(root1.left, root2.right)
        && IsMirror(root1.right, root2.left);
    }
    public bool IsSymmetric(TreeNode root)
    {
        if (root == null) return true;
        return IsMirror(root.left, root.right);
    }
}