package 第四章.检查平衡性;

import 第四章.最小高度树.TreeNode;

public class Solution2 {
    //定义变量减枝
    boolean isBalance = true;

    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        getDepth(root);
        return isBalance;
    }

    private int getDepth(TreeNode node) {
        //如果已经找到不平衡的树枝，不需要递归，直接返回
        if (!isBalance) {
            return 0;
        }
        if (node == null) {
            return 0;
        }
        int left = getDepth(node.left);
        int rignt = getDepth(node.right);
        //判断左右树枝是否平衡，如果不平衡更新减枝变量
        if (Math.abs(left - rignt) > 1) {
            isBalance = false;
        }
        return Math.max(left, rignt) + 1;
    }

//    作者：xiao-chuan-chuan
//    链接：https://leetcode-cn.com/problems/check-balance-lcci/solution/di-gui-shuang-bai-shi-yong-yi-ge-booleanbian-liang/
//    来源：力扣（LeetCode）
//    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}
