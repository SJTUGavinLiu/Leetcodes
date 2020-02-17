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
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return head;
        ListNode* quick = head;
        ListNode* slow = head;
        while(quick->next && quick->next->next)
        {
            slow = slow->next;
            quick = quick->next->next;
            if(slow == quick)
            {
                slow = head;
                while(slow != quick)
                {
                    slow = slow->next;
                    quick = quick->next;
                }
                return slow;

            }
        }
        return NULL;

    }
};