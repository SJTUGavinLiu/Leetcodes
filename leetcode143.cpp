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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)    return;

        ListNode* slow = head;
        ListNode* quick = head;
        while(quick && quick->next &&  quick->next->next)
        {
            quick = quick->next->next;
            slow = slow->next;

        }
        ListNode* list1 = head->next;
        ListNode* list2;
        if(!slow->next->next)
        {
            list2 = slow->next;
        }
        else
        {
            ListNode* pre = slow->next;
            ListNode* cur = slow->next->next;
            ListNode* tmp;
            pre->next = NULL;
            while(cur)
            {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            list2 = pre;
        }

        slow->next = NULL;
        ListNode* p = head;
        while(list1 || list2)
        {
            p->next = list2;
            list2 = list2->next;
            p = p->next;
            p->next = list1;
            if(list1) list1 = list1->next;
            p = p->next;
            //p->next = NULL;
        }

        return;
    }
};