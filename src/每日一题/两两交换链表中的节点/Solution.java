package 每日一题.两两交换链表中的节点;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode good = new ListNode(0);
        good.next = head;
        ListNode p = head;
        ListNode q = head.next;
        ListNode pre = good;

        while (p != null && q != null) {
            p.next = q.next;
            pre.next = q;
            q.next = p;
            if (p.next == null)
                break;
            pre = pre.next.next;
            p = q.next.next;
            // System.out.println(p.val);
            q = p.next;
            // System.out.println(q.val);
        }
        return good.next;
    }
}
