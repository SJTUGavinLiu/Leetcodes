#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)   return nullptr;
        ListNode* tmp = head->next;
        if(!tmp) return head;
        head->next = swapPairs(tmp->next);
        tmp->next=head;
        return tmp;
    }
};