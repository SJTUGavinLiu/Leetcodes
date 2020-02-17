/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode* > st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while(p)
        {
            st.push(p);
            p = p->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        TreeNode* p = cur->right;
        while(p)
        {
            st.push(p);
            p = p->left;
        }
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */