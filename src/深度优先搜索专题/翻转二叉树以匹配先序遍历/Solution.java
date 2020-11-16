package 深度优先搜索专题.翻转二叉树以匹配先序遍历;

import 第四章.最小高度树.TreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public int index = 0;
    public List<Integer> res = new ArrayList<>();

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        if (dfs(root, voyage))
            return res;
        return Arrays.asList(-1);
    }


    public boolean dfs(TreeNode root, int[] voyage) {
        if (root == null)//root为空则在voyage中则对应也不存在，如果存在的话则下面的inex<voyage.length就不对了
        {
            return true;
        }
        if (root.val != voyage[index]) {
            return false;
        }
        index++;
        if (index < voyage.length && root.left != null && root.left.val != voyage[index]) {
            res.add(root.val);//加入节点
            //交换节点进行遍历
            return dfs(root.right, voyage) && dfs(root.left, voyage);
        } else {
            //照常继续进行前序遍历
            return dfs(root.left, voyage) && dfs(root.right, voyage);
        }
    }
}
