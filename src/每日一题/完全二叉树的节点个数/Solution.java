package 每日一题.完全二叉树的节点个数;

import 第四章.最小高度树.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    //dfs
    public int countNode_dfs(TreeNode root) {
        return root == null ? 0 : countNode_dfs(root.left) + countNode_dfs(root.right) + 1;
    }

    //bfs
    public int countNodes_bfs(TreeNode root) {
        if (root == null)
            return 0;
        int count = 0;
        Queue<TreeNode> list = new LinkedList<>();
        list.add(root);
        while (!list.isEmpty()) {
            //poll方法相当于移除队列头部的元素
            TreeNode node = list.poll();
            count++;//统计节点的个数
            if (node.left != null)
                list.add(node.left);
            if (node.right != null)
                list.add(node.right);
        }
        return count;
    }
}
