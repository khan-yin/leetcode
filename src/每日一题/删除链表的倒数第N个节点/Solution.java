package 每日一题.删除链表的倒数第N个节点;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null)
            return head;
        ListNode p = head;
        ListNode q = p;
        int i = 0;
        while (i < n) {
            q = q.next;
            i++;
        }
        if (q == null)
            return p.next;

        while (p != null && q != null && q.next != null) {
            p = p.next;
            q = q.next;
        }
        q = p.next;
        p.next = q.next;
        return head;
    }
}
