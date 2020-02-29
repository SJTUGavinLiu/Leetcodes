class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int min_ = INT_MIN;
        for(auto& item: preorder)
        {
            if(item < min_) return false;
            while(!st.empty() && item > st.top())
            {
                min_ = st.top();
                st.pop();
            }
            st.push(item);
        }
        return true;
    }
};

class Solution {
private:
    bool helper(vector<int>& preorder,int beg, int end)
    {
        if(beg >= end)   return true;
        int i = beg + 1;
        while(i <= end)
        {
            if(preorder[i] > preorder[beg]) break;
            i++;
        }
        int pos = i;
        while(i <= end)
        {
            if(preorder[i] < preorder[beg]) return false;
            i++;
        }

        return helper(preorder, beg+1, pos-1) && helper(preorder, pos, end);
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};


