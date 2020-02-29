class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        while(num)
        {
            st.push(num % 10);
            num /= 10;
        }

        int res = 0;
        while(!st.empty())
        {
            int cur = st.top();
            st.pop();
            if(cur == 6)
            {
                st.push(9);
                break;
            }
            res = res * 10 + cur;
        }

        while(!st.empty())
        {
            res = res * 10 + st.top();
            st.pop();
        }
        return res;
    }
};