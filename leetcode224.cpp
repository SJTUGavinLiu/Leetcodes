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
                if(!st1.empty() && st1.top() != '(')
                {
                    char opr = st1.top();
                    st1.pop();
                    int res;
                    if(opr == '-')
                        res = st2.top() - num;
                    else    
                        res = st2.top() + num;
                    st2.pop();
                    st2.push(res);
                }
                else
                    st2.push(num);
            }
            else
            {
                if(s[i] == ')')
                {
                    st1.pop();
                    while(!st1.empty())
                    {
                        if(st1.top() == '(')
                            break;
                        int obj2 = st2.top();
                        st2.pop();
                        int obj1 = st2.top();
                        st2.pop();
                        if(st1.top() == '-')
                            st2.push(obj1 - obj2);
                        else
                            st2.push(obj1 + obj2);
                        st1.pop();
                    }
                }  
                else
                    st1.push(s[i]);

            }


        }
        
        return st2.empty() ? 0 : st2.top();
    }
};