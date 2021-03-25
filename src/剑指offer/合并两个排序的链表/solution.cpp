#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p =l1;
        ListNode* q =l2;
        ListNode* head = new ListNode(0);
        ListNode* my = head;
        while(p!=NULL&&q!=NULL)
        {
            if(p->val>q->val)
            {
                head->next=q;
                q=q->next;
            }
            else
            {
                head->next = p;
                p=p->next;
            }
            head=head->next;
        }
        while(p!=NULL)
        {
            head->next=p;
            head=head->next;
            p=p->next;
        }
        while(q!=NULL)
        {
            head->next = q;
            head=head->next;
            q=q->next;
        }

        return my->next;
    }
};