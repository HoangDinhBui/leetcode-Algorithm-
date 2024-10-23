/**
 * Definition for a binary tree node.*/
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

public class Solution20
{
    public void LNR(TreeNode root, IList<int> res)
    {
        if (root == null) return;
        LNR(root.left, res);
        res.Add(root.val);
        LNR(root.right, res);
    }

    public IList<int> InorderTraversal(TreeNode root)
    {
        IList<int> res = new List<int>();
        LNR(root, res);
        return res;
    }
}

