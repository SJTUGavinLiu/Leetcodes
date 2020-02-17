class Solution {
private:
    void stackPop(stack<int>& st, int& a, int& b)
    {
        b = st.top();
        st.pop();
        a = st.top();
        st.pop();
    }
    int str2num(string &s)
    {
        int res = 0;
        bool flag = 0;
        for(char c:s)
        {
            if(c == '-')   { flag = 1;  continue;}
            res = res * 10 + (c-'0'); 
        }
        if(flag)    return -res;
        else    return res;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        for(auto& token: tokens)
        {
            if((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.size() > 1))
            {
                st.push(str2num(token));
            }
            else
            {
                stackPop(st, a, b);
                if(token[0] == '+')
                    st.push(a+b);       
                else if (token[0] == '-')
                    st.push(a-b);
                else if(token[0] == '/')
                    st.push(a/b);             
                else if(token[0] == '*')
                    st.push(a*b);
            }
        }
        return st.top();
    }
};