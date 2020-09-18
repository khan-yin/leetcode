package 第二章.环路监测;

import 第二章.移除重复节点.ListNode;

public class Solution {
    //双指针牛逼
    public ListNode detectCycle(ListNode head) {
        if(head==null||head.next==null){
            return null;
        }
        ListNode low=head;
        ListNode fast=head;
        ListNode p;
        while(low!=null&&fast!=null){
            low=low.next;
            fast=fast.next.next;
            if(fast==null||fast.next==null){
                return null;
            }else{
                if(fast==low){
                    break;
                }
            }
        }
        fast=head;
        while(fast!=low){
            fast=fast.next;
            low=low.next;
        }
        return fast;
    }
}
