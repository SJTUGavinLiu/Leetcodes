#include<vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        while(n){
            p1 = p1->next;
            n--;
        }
        ListNode* p2 = head;
        while(p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = p2->next;
        p2->next = p2->next->next;
        delete p1;
        return head;
    }
};