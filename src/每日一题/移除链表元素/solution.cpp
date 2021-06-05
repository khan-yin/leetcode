struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        while(p!=nullptr)
        {
            if(p->val!=val) break;
            p=p->next;
        }
        ListNode* newhead=p;
        while(p!=nullptr&&p->next!=nullptr)
        {
           if(p->next->val==val) p->next = p->next->next;
           else p=p->next;
        }
        return newhead;
    }
};