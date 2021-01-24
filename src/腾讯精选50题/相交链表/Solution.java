package 腾讯精选50题.相交链表;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p = headA;
        ListNode q = headB;
        while (p != q) {
            p = (p != null) ? p.next : headB;
            q = (q != null) ? q.next : headA;
        }
        return p;
    }
}
