static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
private:
    bool helper(ListNode* head, TreeNode* root)
    {
        if(!head)   return true;
        if(!root)   return false;
        if(head->val == root->val && (helper(head->next, root->left) || helper(head->next, root->right)))
            return true;
        return false;
        //return helper(head, root->left) || helper(head, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root && !head)  return true;
        if(!root)   return false;
        if(helper(head, root))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right); 
    }
};