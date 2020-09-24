package 第四章.合法二叉搜索树;

import 第四章.最小高度树.TreeNode;

import java.util.Stack;

public class Solution {
    //error
//    public boolean isValidBST(TreeNode root) {
//        if(root==null)
//            return true;
//        if(root.left!=null&&root.left.val>=root.val){
//            return false;
//        }
//        if(root.right!=null&&root.right.val<=root.val){
//            return false;
//        }
//        return isValidBST(root.left)&&isValidBST(root.right);
//
//    }
    //中序遍历
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        Integer curValue = null;
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            if (cur != null) {
                stack.push(cur);
                cur = cur.left;
            } else {
                cur = stack.pop();
                if (curValue != null && cur.val <= curValue) {
                    return false;
                }
                curValue = cur.val;
                cur = cur.right;
            }
        }
        return true;
    }
}
