package 剑指offer.删除链表的节点;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        while (head != null && head.val == val) {
            head = head.next;
        }

        ListNode p = head;
        while (head != null) {
            if (head.next != null && head.next.val == val)
                head.next = head.next.next;
            head = head.next;
        }
        return p;
    }
}
