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
    void remove(ListNode* pre, ListNode* cur)
    {
        pre->next = cur->next;
        delete cur;
    }
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)   return head;
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        ListNode* pre = dum;
        ListNode* cur = head;
        while(cur)
        {
            while(cur && cur->val == val)
            {
                remove(pre, cur);
                cur = pre->next;
            }
            if(!cur)
                break;
            pre = cur;
            cur = cur->next;
            
        }
        return dum->next;
    }
};