package 第四章.求和路径;

import 第四章.最小高度树.TreeNode;

public class Solution2 {
    private int cnt = 0;
    //加法方式
    private int sum = 0;

    public int pathSum2(TreeNode root, int sum) {
        this.sum = sum;
        if (root == null) return 0;
        dfs(root, 0);
        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return cnt;
    }

    public void dfs2(TreeNode root, int total) {
        if (root == null) return;
        total = total + root.val;
        // System.out.println(total);
        if (total == sum)
            cnt++;

        dfs(root.left, total);
        dfs(root.right, total);
    }

    //减法方式
    public int pathSum(TreeNode root, int sum) {
        if (root == null) return 0;
        dfs(root, sum);
        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return cnt;
    }

    public void dfs(TreeNode root, int sum) {
        if (root == null) return;
        sum = sum - root.val;
        if (sum == 0)
            cnt++;
        dfs(root.left, sum);
        dfs(root.right, sum);
        // sum+=root.val;

    }
//
//    作者：madridista
//    链接：https://leetcode-cn.com/problems/paths-with-sum-lcci/solution/javahui-su-by-madridista/
//    来源：力扣（LeetCode）
//    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}
