/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
void insert(ListNode* pre, ListNode* cur)
{
    ListNode* tmp = pre->next;
    pre->next = cur;
    cur->next = tmp;
}
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)   return NULL;
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* p = dump;
        ListNode* q = dump;
        while(q->next)
        {
            if(q == dump || q->next->val >= q->val)
            {
                q = q->next;
                continue;
            }
            ListNode* cur = q->next;
            q->next = q->next->next;
            
            while(1)
            {
                if(cur->val <= p->next->val)
                {
                    insert(p, cur);
                    p = dump;
                    break;
                }
                p = p->next;
            }
            
        }
        return dump->next;
    }
};