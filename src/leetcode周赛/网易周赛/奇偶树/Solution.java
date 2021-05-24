package 网易周赛.奇偶树;

import 第四章.最小高度树.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        if (root == null) return false;
        Queue<TreeNode> q = new LinkedList<>();

        TreeNode p = root;
        int level = 1;
        q.offer(p);
        while (!q.isEmpty()) {
            level = (level == 0) ? 1 : 0;
            // System.out.println("l="+level);
            LinkedList<TreeNode> one = new LinkedList<TreeNode>();
            while (!q.isEmpty()) {
                TreeNode m = q.poll();
                System.out.println(m.val);
                if (one.isEmpty()) {
                    if (level == 0 && m.val % 2 == 1) {
                        // System.out.println("g1");
                        one.offer(m);
                    } else if (level == 1 && m.val % 2 == 0) {
                        // System.out.println("g2");
                        one.offer(m);
                    } else {
                        // System.out.println("g3");
                        return false;
                    }

                } else {
                    TreeNode ma = one.getLast();
                    // System.out.println("ma="+ma.val);
                    if (level == 0 && ma.val < m.val) {
                        if (m.val % 2 == 1) {
                            // System.out.println("g4");
                            one.offer(m);
                        } else {
                            // System.out.println("g5");
                            return false;
                        }

                    } else if (level == 1 && ma.val > m.val) {
                        if (m.val % 2 == 0) {
                            // System.out.println("g6");
                            one.offer(m);
                        } else {
                            // System.out.println("g7");
                            return false;
                        }

                    } else {
                        // System.out.println("g8");
                        return false;
                    }

                }
            }
            for (TreeNode k : one) {
                if (k.left != null) {
                    q.offer(k.left);
//                    p=p.left;
//                    one.add(k.left);
                }
                if (k.right != null) {
                    q.offer(k.right);
//                    k=k.right;
//                    one.add(k.right)
                }

            }
            // System.out.println("kk");
            // one.push(p.val);


        }
        return true;
    }
}
