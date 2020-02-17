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
    bool hasCycle(ListNode *head) {
        if(!head)   return head;
        ListNode* slow = head;
        ListNode* quick = head;
        while(quick->next && quick->next->next)
        {
            quick = quick->next->next;
            slow = slow->next;
            if(quick == slow)   return true;
        }
        return false;
    }
};