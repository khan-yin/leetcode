/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int depth=0;
    public int res=0;
    public void dfs(TreeNode root,int step)
    {
        if(root!=null)
        {
            if(depth<step)
            {
                depth=step;
                res=root.val;
            }
            dfs(root.left,step+1);
            dfs(root.right,step+1);
        }
    }
    public int findBottomLeftValue(TreeNode root) {
        if(root==null)
            return 0;
        res=root.val;
        dfs(root,0);
        return res;
    }
}