package 链表求和;

import 移除重复节点.ListNode;

import java.math.BigInteger;

public class Solution {
    public static void main(String[] args) {

    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        ListNode p1 = l1;
        ListNode p2 = l2;
        while (p1 != null) {
            s1.append((char) (p1.val + '0'));
            // System.out.println((char)(p1.val+'0'));
            p1 = p1.next;
        }
        // System.out.println(s1.reverse().toString());
        String str1 = s1.reverse().toString();
        while (p2 != null) {
            s2.append((char) (p2.val + '0'));
            p2 = p2.next;
        }
        // System.out.println(s2.reverse().toString());
        String str2 = s2.reverse().toString();
        BigInteger res = new BigInteger(str1).add(new BigInteger(str2));
        System.out.println(res);
        ListNode m = new ListNode(0);
        if (res.compareTo(BigInteger.ZERO) == 0)
            return m;
        else {
            ListNode w = m;
            while (res.compareTo(BigInteger.ZERO) > 0) {
                BigInteger one = res.mod(BigInteger.valueOf(10));
                res = res.divide(BigInteger.valueOf(10));
                w.next = new ListNode(one.intValue());
                w = w.next;
            }
            return m.next;
        }
    }
}
