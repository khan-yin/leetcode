package 腾讯精选50题.反转链表;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode cur = null;
        ListNode pre = head;
        if (head == null || head.next == null) return head;
        while (pre != null) {
            ListNode t = pre.next;
            pre.next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
}
