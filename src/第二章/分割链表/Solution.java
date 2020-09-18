package 第二章.分割链表;

import 第二章.移除重复节点.ListNode;

public class Solution {
    public static void main(String[] args) {
        ListNode ln=new ListNode(1);
        ListNode head=ln;
        int x=3;
        int[] lis={4,3,2,5,2};
        for(int i:lis)
        {
            ListNode p = new ListNode(i);
            ln.next=p;
            ln=ln.next;
        }
        head=partition(head,x);
    }

    //双指针牛逼
    public static ListNode partition2(ListNode head, int x){
        ListNode p=head;//扫描所有元素，遇到小于x的就与前面q的位置对换
        ListNode q=head;//记录大于x的位置
        while(p!=null){
            if (p.val<x){
                int t=p.val;
                p.val=q.val;
                q.val=t;
                q=q.next;
            }
            p=p.next;
        }
        return head;
    }


    public static ListNode partition(ListNode head, int x) {
        if(head==null) return head;
        ListNode xiao=new ListNode(0);
        ListNode tailx=xiao;
        ListNode deng=new ListNode(0);
        ListNode taild=deng;
        ListNode da=new ListNode(0);
        ListNode tailda=da;
        ListNode p=head;
        while(p!=null){
            if(p.val<x){
                tailx.next=new ListNode(p.val);
                tailx= tailx.next;
            }else if(p.val==x){
                taild.next=new ListNode(p.val);
                taild=taild.next;
            }else{
                tailda.next=new ListNode(p.val);
                tailda=tailda.next;
            }
            p=p.next;
        }
        if(xiao.next==null){
            if(deng.next==null){
                return da.next;
            }else{
                taild.next=da.next;
                return deng.next;
            }
        }else{
            if(deng.next==null){
                tailx.next=da.next;
            }else{
                tailx.next=deng.next;
                taild.next=da.next;
            }
            return xiao.next;
        }
    }
}
