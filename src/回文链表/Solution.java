package 回文链表;

import 移除重复节点.ListNode;

public class Solution {
    //反转链表
    public static ListNode reverse(ListNode head){
        ListNode cur=head;
        ListNode prev=null;
        while(cur!=null){
            ListNode nexttemp=cur.next;
            cur.next=prev;
            prev=cur;
            cur=nexttemp;
        }
        return prev;
    }

    //快慢指针寻找middle
    public static ListNode findmiddleNode(ListNode head){
        ListNode low=head;
        ListNode fast=head;
        while(fast.next!=null && fast.next.next!=null){
            low=low.next;
            fast=fast.next.next;
        }
        return low;
    }

    public boolean isPalindrome(ListNode head) {
        if(head==null) return true;
        ListNode mid=findmiddleNode(head);
        ListNode behind=reverse(mid.next);
        ListNode p=head;
        ListNode q=behind;
        while(q!=null){
            if(p.val!=q.val)
            {
                return false;
            }
            p=p.next;
            q=q.next;
        }
        return true;
    }
}
