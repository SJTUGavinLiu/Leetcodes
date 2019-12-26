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
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return NULL;
        ListNode* dump1 = new ListNode(-1);
        ListNode* dump2 = new ListNode(-1);
        dump2->next = head;
        ListNode* p = dump1;
        ListNode* q = dump2;
        ListNode* tail = dump1;
        ListNode* tmp;
        while(q->next)
        {
            tmp = q->next;
            if(tmp->val < x)
            {
                q->next = tmp->next;
                tail->next = tmp;
                tail = tmp;
            }
            else
                q = q->next;
            
        }
        tail->next = dump2->next;
        return dump1->next;



    }
};