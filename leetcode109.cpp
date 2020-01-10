/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* head)
    {
        if(!head)   return NULL;

        TreeNode* tmp;
        if(!head->next)
        {
            tmp = new TreeNode(head->val);
        }
        else
        {
            ListNode* slow = head;
            ListNode* quick = head->next;
            while(quick->next && quick->next->next)
            {
                quick= quick->next->next;
                slow = slow->next;
            }

            tmp = new TreeNode(slow->next->val);
            
            tmp->right = helper(slow->next->next);
            slow->next = NULL;
            tmp->left = helper(head);
        }

        return tmp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};