package 腾讯精选50题.旋转链表;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode move(ListNode head) {
        ListNode p = head;
        while (p.next.next != null) {
            p = p.next;
        }
        ListNode tail = p.next;
        tail.next = head;
        p.next = null;
        head = tail;
        return head;
    }

    public int getLength(ListNode head) {
        ListNode p = head;
        int length = 0;
        while (p != null) {
            length++;
            p = p.next;
        }
        return length;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0)
            return head;
        int length = getLength(head);
        // System.out.println(length);
        k = k % length;
        while (k-- > 0) {
            head = move(head);
        }
        return head;
    }
}
