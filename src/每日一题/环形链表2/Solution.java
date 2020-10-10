package 每日一题.环形链表2;

import 第二章.移除重复节点.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution {
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
