/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    ListNode* cut(ListNode* head, int step) // divide a sublist with length 'step' off the list
    {
        if(!head)   return NULL;
        ListNode* p = head;
        while(p->next && step-1)
        {
            p = p->next;
            step--;
        }
        ListNode *tmp = p->next;
        p->next = NULL;
        return tmp;
    }
    ListNode* merge(ListNode* r, ListNode* list1, ListNode* list2)
    {
        ListNode* p = list1;
        ListNode* q = list2;
        while(p || q)
        {
            if(!q)
            {
                r->next = p;
                while(p->next)
                    p = p->next;
                return p;
            }
            else if(!p)
            {
                r->next = q;
                while(q->next)
                    q = q->next;
                return q;
            }
            if(p->val > q->val)
            {
                r->next = q;
                q = q->next;
            }
            else
            {
                r->next = p;
                p = p->next;
            }
            r = r->next;
            r->next = NULL;
        }
        return r;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head)   return NULL;
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        int step = 1;
        ListNode* pre = dum;
        ListNode* cur = head;
        int cnt = 0;
        while(1)
        {
            pre = dum;
            cur = dum->next;
            cnt = 0;
            while(cur)
            {
                ListNode* first = cur;
                ListNode* second = cut(cur, step);
                cur = cut(second, step);
                pre = merge(pre, first, second);
                cnt++;
            }

            if(cnt == 1)    break;
            step *= 2;
            
        }
        return dum->next;
    }
};