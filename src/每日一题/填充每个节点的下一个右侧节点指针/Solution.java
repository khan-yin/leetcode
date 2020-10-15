package 每日一题.填充每个节点的下一个右侧节点指针;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public Node connect(Node root) {
        if (root == null)
            return root;

        Queue<Node> queue = new LinkedList<Node>();
        Node p = root;
        queue.offer(p);
        p.next = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            Node temp = null;
            for (int i = 0; i < size; i++) {
                Node q = queue.poll();
                // System.out.println(q.val);
                if (temp == null) {
                    temp = q;
                    temp.next = null;
                } else {
                    temp.next = q;
                    temp = temp.next;
                }

                if (q.left != null)
                    queue.offer(q.left);
                if (q.right != null)
                    queue.offer(q.right);

            }
        }
        return root;
    }
}
