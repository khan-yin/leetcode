package k;

import 移除重复节点.ListNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int k=3;
        ListNode head = new ListNode(1);
        solution.kthToLast(head,k);
    }

    public int kthToLast(ListNode head, int k) {
        ListNode p=head;
        List<Integer> s = new ArrayList<>();
        while (p!=null)
        {
            s.add(p.val);
            p=p.next;
        }
        return s.get(s.size()-k);
    }
}
