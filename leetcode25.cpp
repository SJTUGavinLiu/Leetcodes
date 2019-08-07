#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)  return head;
        ListNode *tmp = head;
        for(int i = 0; i < k; i++)
        {
            if(!tmp)    return head;
            tmp = tmp -> next;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        head->next = reverseKGroup(tmp,k);
        
        for(int i = 1; i < k; i++)
        {
            tmp = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};