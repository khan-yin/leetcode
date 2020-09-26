package 第四章.路径总和II;

import 第四章.最小高度树.TreeNode;

import java.util.LinkedList;
import java.util.List;

public class Solution {
    private int cnt = 0;
    public List<List<Integer>> list = new LinkedList<List<Integer>>();
    public LinkedList<Integer> path = new LinkedList<Integer>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        // if(root==null) return null;
        dfs(root, sum);
        // pathSum(root.left,sum);
        // pathSum(root.right,sum);
        return list;
    }

    public void dfs(TreeNode root, int sum) {
        if (root == null) return;
        path.offerLast(root.val);
        sum = sum - root.val;
        if (sum == 0 && root.left == null && root.right == null)
            list.add(new LinkedList<Integer>(path));
        dfs(root.left, sum);
        dfs(root.right, sum);
        path.pollLast();
        // sum+=root.val;

    }
}
