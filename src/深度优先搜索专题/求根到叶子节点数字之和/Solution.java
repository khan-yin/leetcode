package 深度优先搜索专题.求根到叶子节点数字之和;

import 第四章.最小高度树.TreeNode;

public class Solution {
    public int total = 0;

    public void dfs(TreeNode root, int sum) {
        if (root != null) {
            sum += root.val;
            if (root.left == null && root.right == null)
                total += sum;
            dfs(root.left, sum * 10);
            dfs(root.right, sum * 10);

        }
    }

    public int sumNumbers(TreeNode root) {
        int sum = 0;
        dfs(root, sum);
        return total;
    }
}
