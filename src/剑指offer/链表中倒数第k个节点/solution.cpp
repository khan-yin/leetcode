#include<iostream>
#include<cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p =head;
        ListNode* q=p;
        while(k--)
        {
            p=p->next;
        }
        while(p!=NULL&&q!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};