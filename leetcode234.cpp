class Solution {
public:
    bool isPalindrome(ListNode* head) {//O(n)、O(1)
        if(!head || !head->next)    return true; 
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = NULL;
        //slow = slow->next;
        while(slow)
        {
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }

        while(head && pre)
        {
            if(head->val != pre->val)
                return false;
            head = head->next;
            pre = pre->next;
        }

        return true;



        
    }
};