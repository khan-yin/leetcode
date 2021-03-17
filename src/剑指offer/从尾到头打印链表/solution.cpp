/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};


class Solution {
public:
    int m[10005];
public:
    vector<int> reversePrint(ListNode* head) {
        int cnt=0;
        vector<int> res;
        while(head!=NULL)
        {
            m[cnt++]=head->val;
            head=head->next;
        }
        for(int i=cnt-1;i>=0;i--)
        {
            res.push_back(m[i]);
        }
        return res;

    }
};