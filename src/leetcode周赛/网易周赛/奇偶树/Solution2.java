package 网易周赛.奇偶树;

import 第四章.最小高度树.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution2 {
    public boolean isEvenOddTree(TreeNode root) {
        if (root == null || root.val % 2 == 0) return false;
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode p = root;
        int level = 1000001;
        q.offer(p);
        while (!q.isEmpty()) {
            int size = q.size();
            level = (level != 0) ? 0 : 1000001;
            int cur = 0;
            boolean fl = true;
            System.out.println("l=" + level);
            for (int i = 0; i < size; i++) {
                TreeNode m = q.poll();

                System.out.println(m.val);
                if (m.left != null) {
                    q.offer(m.left);
                }
                if (m.right != null) {
                    q.offer(m.right);
                }
                if (fl) {
                    fl = false;
                    if ((level == 0 && m.val % 2 == 1) || (level == 1000001 && m.val % 2 == 0))
                        cur = m.val;
                    else
                        return false;
                    continue;
                }
                if (level == 0) {
                    if (cur >= m.val || m.val % 2 == 0) {
                        return false;
                    }
                } else {
                    if (cur <= m.val || m.val % 2 == 1) {
                        return false;
                    }
                }
                cur = m.val;
            }
        }
        return true;
    }
}
