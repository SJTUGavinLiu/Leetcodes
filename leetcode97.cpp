class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size() + s2.size()) != s3.size())
            return false;
        int len1 = s1.size();
        int len2 = s2.size();

        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= len1; i++)
        {
            if(s1[i-1] == s3[i-1])
                dp[i][0] = 1;
            else 
                break;
        }

        for(int j = 1; j <= len2; j++)
        {
            if(s2[j-1] == s3[j-1])
                dp[0][j] = 1;
            else 
                break;
        }


        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {

                dp[i][j] = (s1[i-1] == s3[i+j-1] ? dp[i-1][j]: 0) || (s2[j-1] == s3[i+j-1] ? dp[i][j-1] : 0);

            }
        }

        /*
        for(int i = 0; i <= len1; i++)
        {
            for(int j = 0; j <= len2; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[len1][len2];
        */


    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size() + s2.size()) != s3.size())
            return false;
        int len1 = s1.size();
        int len2 = s2.size();

        vector<int> dp(len2+1, 0);
        int flag = 1;


        dp[0] = 1;
        for(int j = 1; j <= len2; j++)
        {
            if(s2[j-1] == s3[j-1])
                dp[j] = 1;
            else 
                break;
        }
        

        for(int i = 1; i <= len1; i++)
        {
            if(flag)
            {
                if(s1[i-1] == s3[i-1])
                    dp[0] = 1;
                else
                {
                    dp[0] = 0;
                    flag = !flag;
                }
            }

        

            for(int j = 1; j <= len2; j++)
            {
                dp[j] = (s1[i-1] == s3[i+j-1] ? dp[j]: 0) || (s2[j-1] == s3[i+j-1] ? dp[j-1] : 0);
            }

  

        }

        
        return dp[len2];

    }
};