package 第四章.检查子树;

import 第四章.最小高度树.TreeNode;

public class Solution {
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if (t2 == null) {
            return true;
        }
        if (t1 == null) {
            return false;
        }
        if (t1.val != t2.val) {
            return checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
        } else if (IsSameTree(t1.left, t2.left) && IsSameTree(t1.right, t2.right)) {
            return true;
        }
        return checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
    }

    public boolean IsSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }

        return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}
