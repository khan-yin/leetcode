package 每日一题.环形链表2;

import 第二章.移除重复节点.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    //快慢指针法
    public ListNode detectCycle2(ListNode head) {
        ListNode fast = head;
        ListNode low = head;
        ListNode together = null;
        while (fast != null && low != null && fast.next != null) {
            fast = fast.next.next;
            low = low.next;
            if (fast == low) {
                together = fast;
                break;
            }
        }
        if (together == null)
            return together;
        else {
            // System.out.println(together.val);
            ListNode p = head;
            ListNode q = together;
            while (p != null && q != null) {
                if (p == q)
                    return p;
                p = p.next;
                q = q.next;
            }
        }
        return null;
    }

    //哈希集合法
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return null;
        ListNode pos = head;
        Set<ListNode> visited = new HashSet<ListNode>();
        while (pos != null) {
            if (visited.contains(pos)) {
                return pos;
            } else {
                visited.add(pos);
            }
            pos = pos.next;
        }
        return null;
    }
}
