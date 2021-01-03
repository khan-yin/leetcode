/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* min = new ListNode(0);
        ListNode* max = new ListNode(0);
        ListNode* p=head;
        ListNode* pmin = min;
        ListNode* pmax = max;
        while(p!=nullptr)
        {
            if(p->val <x)
            {
                min->next=p;
                min=min->next;
            }
            else
            {
                max->next=p;
                max=max->next;
            }
            p=p->next;
        }
        max->next = nullptr;
        min->next = pmax->next;
        return pmin->next;
    }
};