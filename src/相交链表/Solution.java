package 相交链表;

import 移除重复节点.ListNode;

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA==null||headB==null) return null;
        ListNode t1=headA;
        ListNode t2=headB;
        while(t1 != t2){
            t1 = t1 != null ? t1.next : headB;
            t2 = t2 != null ? t2.next : headA;
            // t1 = t1 == null ? headB:t1.next;
            // t2 = t2 == null ? headA:t2.next;
        }
        return t2;
    }
}
