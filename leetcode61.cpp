 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)    return head;
        ListNode* dump = new ListNode;
        dump->next = head;

        int len = 1
        for(ListNode* p = head; !p; p = p->next)
            len++;
        k = k % len;
        if(k ==)
        ListNode* p = dump;
        while(k--)
            p = p->next;
        ListNode* q =dump;
        
        while(p->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = dump->next;
        dump->next = q->next;
        q->next = NULL;
        return dump->next;
    }
};