class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int i1 = 0, i2 = 1;
        int len1 = s1.size(), len2 = s2.size();
        int begPos = -1; //用来记录s1串上的第一个起始位置
        while(i1 < len1)
        {
            if(s1[i1] == s2[0])
            {
                begPos = i1;
                i1++;
                break;
            }
            i1++;
        }

        int cnt = 0;
        bool intersect = 0;
        int count1 = 1;
        int count2 = 1;
        int endPos = len1-1;
        vector<int> list;
        while(1)
        {
            i1 = i1 % len1;
            i2 = i2 % len2;

            if(i2 == 0){
                endPos = (len1 + i1 - 1) % len1; 
                count2++;
                list.push_back(count1);
            }
            if(i1 == 0) count1++;
            if(cnt > len1)  return 0;
            if(begPos == i1 && i2 == 0) break;

            if(s1[i1] == s2[i2])
            {
                i2++;
                cnt = 0;
            }    
            i1++;
            cnt++;
        }

        count1--;
        count2--;


        if(endPos == len1 - 1)
        {
            intersect = 0;
        }
        else
        {
            bool flag = 1;
            int i = endPos + 1;
            int j = 0;
            while(flag || i != begPos)
            {
                if(s1[i] == s2[j])  
                {
                    j++;
                    if(j == len2)
                    {
                        intersect = 1;
                        break;
                    }
                }
                i++;
                if(i == len1)
                {
                    flag = 0;
                    i = 0;
                }
            }
        }

        int res = n1 / count1 * count2 + (intersect ? (n1/count1 - 1) : (0));
        if(n1 % count1 != 0)
        {
            res += intersect;
            int i;
            for(i = 0; i < list.size(); i++)
            {
                if(list[i] > (n1 % count1)) break;
            }
            res += i;
        }
        return res / n2;
        


    }
};