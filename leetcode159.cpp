class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())   return 0;

        //bool firstAvail = 1;
        //bool second Avail = 1;
        int firstChar = -1;
        int secondChar = -1;
        int firstPos = 0;
        int secondPos = 0;

        int left = 0;
        int right = 0;
        int res = 0;

        while(right < s.size())
        {
            //cout<<left;

            if(s[right] == firstChar)
            {
                firstPos = right;
            }
            else if(s[right] == secondChar)
            {
                secondPos = right;
            }
            else
            {
                if(firstChar == -1)
                {
                    firstChar = s[right];
                    firstPos = right;
                }
                else if(secondChar == -1)
                {
                    secondChar = s[right];
                    secondPos = right;  
                }
                else
                {
                    res = max(res, right - left);
                    if(secondPos > firstPos)
                    {
                        left = firstPos+1;
                        firstPos = right;
                        firstChar = s[right];
                    }
                    else
                    {
                        left = secondPos+1;
                        secondPos = right;
                        secondChar = s[right];
                    }
                }
            }
        
            right++;
        }
        return max(res, right - left);
    }
};