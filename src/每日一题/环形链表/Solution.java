package 每日一题.环形链表;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;
        ListNode p = head;
        ListNode q = p.next;
        while (p != null && q != null && q.next != null) {
            if (p == q)
                return true;
            p = p.next;
            q = q.next.next;

        }
        return false;
    }
}
