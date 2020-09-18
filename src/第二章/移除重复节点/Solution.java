package 第二章.移除重复节点;

import java.util.*;

public class Solution {
    public static void main(String[] args) {
        int[] lis={17, 23, 15, 30, 21, 5, 20,
                14, 5, 9, 22, 6, 22, 20, 14, 12, 4, 21, 27, 5, 4, 21, 27, 0, 14, 21, 17, 27, 6, 12, 28, 17, 29, 8, 17, 13, 7, 26, 7, 31, 27, 8, 31, 19, 5, 23, 9, 0, 22, 0, 26, 30, 14, 10, 6, 8, 16, 24, 15, 21, 2, 3, 5, 15};
        ListNode a= new ListNode(lis[0]);
        ListNode t=a;
//        ListNode tt=a.next;
//        System.out.println(a.hashCode());
//        System.out.println(a.next.hashCode());
//        System.out.println(tt.hashCode());
//        System.out.println(tt.hashCode());
        for(int i=1;i<lis.length;i++)
        {
            t.next=new ListNode(lis[i]);
            t=t.next;
        }
        t.next = new ListNode(2);
        Solution solution = new Solution();
        a=solution.removeDuplicateNodes(a);
        System.out.println(a);
    }

    public ListNode removeDuplicateNodes(ListNode head) {
//        Queue<String> q = new LinkedList<>();
        Map<Integer,ListNode> map=new HashMap<>();
        List<Integer> list=new ArrayList<>();
        ListNode temp=head;
        while(temp!=null)
        {
            ListNode ms=map.get(temp.val);
            if(ms==null)
            {
                list.add(temp.val);
                map.put(temp.val,temp);
            }
            temp=temp.next;
        }
        ListNode t=head;
        ListNode q=t;
        int flag=0;
        for (int key : list) {
            // System.out.println(map2.get(key));
            if (flag == 0) {
                flag = 1;
            } else {
                t.next = new ListNode(key);
                t = t.next;
            }

            // System.out.println(key + " = " + value);
        }
        return q;
    }

    //set方法
    public ListNode removeDuplicateNodes2(ListNode head){
        Set<Integer> set = new HashSet<>();
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            set.add(cur.val);
            if (set.contains(cur.next.val))
                cur.next = cur.next.next;
            else
                cur = cur.next;
        }
        return head;

// 作者：sdwwld
// 链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci/solution/javade-4chong-xie-fa-bao-gua-di-gui-wei-yun-suan-b/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//        if(head==null){
//            return head;
//        }
//        Set<Integer> set = new HashSet<>();
//        ListNode p = head;
//        set.add(p.val);
//        while(p.next!=null){
//            if(set.contains(p.next.val)){
//                p.next=p.next.next;
//            }else{
//                p=p.next;
//                set.add(p.val);
//            }
//        }
//        return head;
    }


    //双指针
    public ListNode removeDuplicateNodes3(ListNode head){
        ListNode p=head;
        while(p!=null)
        {
            ListNode q=p;
            while(q.next!=null)
            {
                if(q.next.val==p.val){//特别注意这个条件
                    q.next=q.next.next;
                }else{
                    q=q.next;
                }
            }
            p=p.next;
        }
        return head;
//
//        作者：sdwwld
//        链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci/solution/javade-4chong-xie-fa-bao-gua-di-gui-wei-yun-suan-b/
//        来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    }

}

