package 第四章.后继者;

import 第四章.最小高度树.TreeNode;

import java.util.Stack;

public class Solution {
    //中序遍历法
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode m = root;
        if (m == null) return null;
        boolean f = false;
        while (m != null || !stack.isEmpty()) {
            if (m != null) {
                stack.push(m);
                m = m.left;
            } else {
                m = stack.pop();
                System.out.println(m.val);
                if (f) {
                    return m;
                }
                if (m == p) {
                    f = true;
                }
                m = m.right;
            }
        }
        return null;
    }
}
