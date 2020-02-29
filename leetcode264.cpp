class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);
        int i1 = 0, i2 = 0, i3 = 0;
        int tmp;
        for(int i = 1; i < n; i++)
        {
            tmp = min(res[i1] * 2, min(res[i2] * 3, res[i3] * 5));
            res.push_back(tmp);
            if(tmp == res[i1] * 2)
                i1++;
            if(tmp == res[i2] * 3)
                i2++;
            if(tmp == res[i3] * 5)
                i3++;
        }
        return res.back();

    }
};





class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)  return 1;
        //vector<int> dp(n+1);
        unordered_set<int> st;
        int i = 2;
        int num = 2;
        st.insert(1);

        while(i <= n)
        {
            while(1)
            {
                if((num % 2 == 0 && st.count(num / 2)) || (num % 3 == 0 && st.count(num / 3)) || (num % 5 == 0 && st.count(num / 5)))
                {
                    st.insert(num);
                    i++;
                    num++;
                    break;   
                }
                num++;
            }

        }

        return num - 1;

    }
};