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

    void recoverTree(TreeNode* root) {
        if(!root)   return;
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        TreeNode* p = root;
        while(p->left)
        {
            st.push(p->left);
            p = p->left;
        }

        TreeNode* p1 = NULL; 
        TreeNode* p2 = NULL;
        TreeNode* q;
        int flag = 0;
        int pre = 0;

        while(!st.empty())
        {
            p = st.top();
            st.pop();
            q = p->right;
            while(q)
            {
                st.push(q);
                q = q->left;
            }
            
            if(!p1 && p->val > st.top()->val)
            {
                p1 = p;
                TreeNode* tmp = st.top();
                st.pop();
                q = tmp->right;
                while(q)
                {
                    st.push(q);
                    q = q->left;
                }
                if(st.empty() || st.top()->val > p1->val)
                {

                    p2 = tmp;
                    break;
                }
                flag = 1;
                pre = tmp->val;
                continue;
                
            }
            if(flag && !p2 && (st.empty() || p->val < pre))
            {

                p2 = p;
                break;
            }
            pre = p->val;
            
            
        }


        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
        
        
        return ;

    }


};