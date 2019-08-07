#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return nullptr;
        int interval = 1;
        while(interval < lists.size())
        {
            for(int i = 0; i < lists.size() - interval; i += interval * 2)
            {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
    
    ListNode* merge(ListNode* p, ListNode* q)
    {
        ListNode* dump = new ListNode(0); 
        ListNode* pt = dump;

        while(p && q)
        {
            if(p->val < q->val) 
            {
                pt->next = p;
                p = p -> next;
            }
            else 
            {
                pt->next = q;
                q = q -> next;
            }
            pt = pt->next; 
        }
        if(p)   pt->next = p;
        else pt->next = q;

        return dump -> next;
    }
};