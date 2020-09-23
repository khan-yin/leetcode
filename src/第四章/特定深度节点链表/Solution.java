package 第四章.特定深度节点链表;

import 第二章.移除重复节点.ListNode;
import 第四章.最小高度树.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;

public class Solution {
    public static ListNode[] listOfDepth(TreeNode tree) {
        LinkedList<TreeNode> q = new LinkedList<>();
        ArrayList<ListNode> good = new ArrayList<>();
        if (tree == null) {
            return null;
        }
        q.offer(tree);
        // good.add(new ListNode(tree.val));
        // TreeNode p=tree;
        while (!q.isEmpty()) {
            int size = q.size();
            System.out.println(size);
            // LinkedList<TreeNode> p=q;
            // ListNode m=new ListNode();
            // ArrayList<ListNode> list=new ArrayList<>();
            ListNode t = new ListNode(0);
            if (!q.isEmpty()) {
                int i = 0;
                ListNode cur = t;
                while (i < size) {
                    TreeNode k = q.poll();
                    cur.next = new ListNode(k.val);
                    // list.add(new ListNode(k.left.val));
                    if (k.left != null) {
                        q.offer(k.left);
                    }
                    if (k.right != null) {
                        q.offer(k.right);
                    }
                    i++;
                    cur = cur.next;
                }
                good.add(t.next);
            }
        }
        return good.toArray(new ListNode[]{});
    }
}
