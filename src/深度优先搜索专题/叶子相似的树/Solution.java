package 深度优先搜索专题.叶子相似的树;

import 第四章.最小高度树.TreeNode;

import java.util.ArrayList;

public class Solution {
    public void dfs(TreeNode root, ArrayList<TreeNode> nodelist) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            nodelist.add(root);
            return;
        } else {
            if (root.left != null)
                dfs(root.left, nodelist);
            if (root.right != null)
                dfs(root.right, nodelist);
        }
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }
        ArrayList<TreeNode> nodelist1 = new ArrayList<>();
        ArrayList<TreeNode> nodelist2 = new ArrayList<>();
        dfs(root1, nodelist1);
        dfs(root2, nodelist2);
        if (nodelist1.size() != nodelist2.size())
            return false;
        for (int i = 0; i < nodelist1.size(); i++) {
            TreeNode one = nodelist1.get(i);
            TreeNode two = nodelist2.get(i);
            if (one.val != two.val)
                return false;
        }
        return true;
    }
}
