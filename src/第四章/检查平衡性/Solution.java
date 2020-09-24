package 第四章.检查平衡性;

import 第四章.最小高度树.TreeNode;

import java.util.LinkedList;

public class Solution {
    public static int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 当前二叉树的高度 = max(左子树高度,右子树高度) + 1
        return Math.max(depth(root.left), depth(root.right)) + 1;
//        int dleft=0;
//        int dright=0;
//        if(root==null){
//            return 0;
//        }
//        if(root.left==null&&root.right==null){
//            return 1;
//        }
//        if(root.left!=null){
//            dleft+=1+depth(root.left);
//        }
//        if(root.right!=null)
//        {
//            dright+=1+depth(root.right);
//        }
//        return dleft>dright?dleft:dright;
    }

    public boolean isBalanced(TreeNode root) {
        // 根结点为null，说明是棵空树，认为是平衡的
        if (root == null) {
            return true;
        }
        int leftTreeDepth = depth(root.left);   // 左子树高度
        int rightTreeDepth = depth(root.right); // 右子树高度
        if (Math.abs(leftTreeDepth - rightTreeDepth) > 1) {
            return false;   // 高度差大于1说明不平衡
        }
        // 若以当前节点为根的子树是平衡的，继续递归检查它左右子树的平衡性
        return isBalanced(root.left) && isBalanced(root.right);
//
//        作者：zui-weng-jiu-xian
//        链接：https://leetcode-cn.com/problems/check-balance-lcci/solution/xin-shou-di-gui-jie-fa-by-zui-weng-jiu-xian/
//        来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        //bfs思路
//        if(root==null){
//            return true;
//        }
//        LinkedList<TreeNode> q= new LinkedList<>();
//        q.offer(root);
//        while(!q.isEmpty()){
//            TreeNode w=q.poll();
//            int l=depth(w.left);
//            int r=depth(w.right);
//            if(l-r>1||l-r<-1){
//                return false;
//            }
//            if(w.left!=null){
//                q.offer(w.left);
//            }
//            if(w.right!=null){
//                q.offer(w.right);
//            }
//        }
//        return true;

    }
}
