class Solution {
public:
    int calculate(string s) {
        stack<char> st1;
        stack<long> st2;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            else if(s[i] >= '0' && s[i] <='9')
            {
                long num = 0;
                while(i < s.size())
                {
                    if(s[i] < '0' || s[i] > '9')
                    {
                        i--;
                        break;
                    }
                    num = 10 * num + s[i] - '0';
                    i++;
                }

                if(!st1.empty() && (st1.top() == '*' || st1.top() == '/'))
                {
                    int res;
                    if(st1.top() == '*')
                    {
                        res = st2.top() * num;
                        st2.pop();
                    }
                    else
                    {
                        res = st2.top() / num;
                        st2.pop();
                    }
                    st1.pop();
                    st2.push(res);
                }
                else
                    st2.push(num);
            }
            else
                st1.push(s[i]);


        }
        int res = 0;
        while(!st1.empty())
        {
            int obj = st2.top();
            st2.pop();

            if(st1.top() == '-')
                res += (-obj);
            else
                res += obj;
            
            st1.pop();
        }
        return (st2.empty() ? 0 : st2.top()) + res;
    }
};