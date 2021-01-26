package 腾讯精选50题.二叉搜索树中第K小的元素;

import 第四章.最小高度树.TreeNode;

public class Solution {
    int target = 0;
    int count = 0;

    public void findk(TreeNode root, int k) {
        if (root != null) {
            findk(root.left, k);
            this.count++;
            if (count == k) {
                this.target = root.val;
                return;
            }
            findk(root.right, k);
        }
    }

    public int kthSmallest(TreeNode root, int k) {
        findk(root, k);
        return this.target;
    }
}
