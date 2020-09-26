package 第四章.求和路径;

import 第四章.最小高度树.TreeNode;

public class Solution {
    // public int total=0;
    public int cnt = 0;
    public int sum = 0;

    public void dfs(TreeNode root, int total) {

        if (root == null) {
//            System.out.println("x");
            return;
        } else {
            total += root.val;
        }
        System.out.println(total);
        if (total == sum) {
            cnt++;
//            System.out.println("cnt=" + cnt);
        }
        dfs(root.left, total);
        dfs(root.right, total);
    }

    public void qianxu(TreeNode root) {
        if (root == null) {
            return;
        }
        int total = 0;
        dfs(root, total);
        if (root.left != null) {
            qianxu(root.left);
            // System.out.println(root.left.val);
        }
        if (root.right != null) {
            qianxu(root.right);
        }

    }

    public int pathSum(TreeNode root, int sum) {
        this.sum = sum;
        qianxu(root);
        return this.cnt;
    }


}
