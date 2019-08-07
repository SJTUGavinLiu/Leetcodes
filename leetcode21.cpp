#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        ListNode* p=l1, *q=l2;
        int val1,val2;
        while(p || q)
        {
            val1=p?p->val:INT_MAX;
            val2=q?q->val:INT_MAX;
            cur->next=new ListNode(0);
            cur=cur->next;
            if(val1<val2)
            {
                cur->val=val1;
                p=p->next;
            }
            else
            {
                cur->val=val2;
                q=q->next;
            }
        }
        return res->next;
        
    }
};