/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* res= new ListNode(0);
        ListNode* rhead=res;
        while(p!=nullptr&&q!=nullptr)
        {
            if(p->val<=q->val)
            {
                rhead->next=new ListNode(p->val);
                rhead=rhead->next;
                p=p->next;
            }
            else
            {
                rhead->next=new ListNode(q->val);
                rhead=rhead->next;
                q=q->next;
            }
        }
        if(p!=nullptr) rhead->next=p;
        if(q!=nullptr) rhead->next=q;
        return res->next;
    }
};