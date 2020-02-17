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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        bool flag1 = 1;
        bool flag2 = 1;

        while(p || q)
        {
            if(p == q)  return p;
            p = p->next;
            q = q->next;
            if(!p)
            {
                if(flag1)
                {
                    p = headB;
                    flag1 = false;
                }
                else
                    break;
            }
            if(!q)
            {
                if(flag2)
                {
                    q = headA;
                    flag2 = false;
                }
                else    
                    break;
            }
        }
        return NULL;
    }
};