using System;
using System.Collections.Generic;
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

public class Solution21
{
    public bool isSameNode(int x, int y)
    {
        return x == y;
    }
    public bool IsSameTree(TreeNode p, TreeNode q)
    {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        return isSameNode(p.val, q.val) && IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}