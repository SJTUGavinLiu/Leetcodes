/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)   return NULL;
        if(m >= n)  return head;
        ListNode* dump = new ListNode(-1);
        ListNode* pre, * tail_, * head_, *latt;
        ListNode* p, *q;
        dump->next = head;
        int cnt = m - 1;
        pre = dump;
        p = head;
        while(cnt)
        {
            pre = p;
            p = p->next;
            cnt--;
        }

        cnt = n - m;
        tail_ = p;
        q = p;
        p = p->next;
        ListNode* tmp;
        while(cnt)
        {
            tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
            cnt--;
        }
        latt = p;
        head_ = q;

        pre->next = head_;
        tail_->next = latt;

        return dump->next;

    }
};