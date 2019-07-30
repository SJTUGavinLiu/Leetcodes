#include<iostream>
#include<vector>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode(0); //dump
        ListNode *p, *p1, *p2;
        p = res;
        p1 = l1;
        p2 = l2;
        int carry = 0, num1, num2, sum = 0;
        while(p1 || p2)
        {
            num1 = p1 ? (p1->val) : 0;
            num2 = p2 ? (p2->val) : 0;
            sum = carry + num1 + num2;
            if(sum > 9){
                sum -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            p -> next = new ListNode(sum);
            p = p -> next;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }
        
        if(carry)
        {
            p -> next = new ListNode(1); 
        }
        return res->next;

    }
};