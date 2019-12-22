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
    void deleteNode(ListNode* pre, ListNode* cur)
    {
        pre -> next = cur -> next;
        delete cur;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return NULL;

        ListNode* pre = new ListNode(-1);
        ListNode* cur = head;
        ListNode* dump = pre;
        pre->next = head;


        int cnt = 1;

        while(cur)
        {
            if(!cur->next)  break;
            if(cur->next->val == cur -> val)
            {
                int tmp = cur -> val;
                while(cur->val == tmp)
                {
                    deleteNode(pre,cur);
                    cur = pre->next;
                    if(!cur)    break;
                }
            }
            else
            {
                pre = cur;
                cur = cur -> next;
            }
            
        }
        return dump -> next;

    }
};