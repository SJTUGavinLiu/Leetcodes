/* both front and back */

/*
class Solution {
private:
    int Max = INT_MIN;
    int left;
    int right;
    int radius;
    void helper(int l, int r,  string& s)
    {
        int i = l;
        int j = r;
        while(i >= 0 && j < s.size())
        {
            if(s[i] != s[j])
                break;
            i--;
            j++;
            
        }
        if((i == -1 || j == s.size()) && (j-i-1) > Max)
        {
            Max = j - i -1;
            left = l;
            right = r;
            radius = j - r - 1;
        } 
    }
public:
    string shortestPalindrome(string s) {
        int len = s.size();

        for(int i = 0; i < len; i++)
        {
            helper(i,i,s);
            helper(i,i+1,s);
        }
        string res = s;
        int l = left - radius;
        int r = right + radius;
        if(r == len - 1)
        {
            l--;
            while(l >= 0)
            {
                res = res + s[l];
                l--;
            }
        }
        else if(l == 0)
        {
            r++;
            while(r < len)
            {
                res = s[r] + res;
                r++;
            }
                
        }
        return res;
    }
};
*/
/* only front */


/*
class Solution {
private:
    int Max = INT_MIN;
    int left;
    int right;
    int radius;

    void helper(int l, int r,  string& s)
    {
        int i = l;
        int j = r;
        while(i >= 0 && j < s.size())
        {
            if(s[i] != s[j])
                break;
            i--;
            j++;
            
        }
        if( i == -1  && (j-i-1) > Max)
        {
            Max = j - i -1;
            left = l;
            right = r;
            radius = j - r - 1;
        } 
    }
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            helper(i,i,s);
            helper(i,i+1,s);
        }
        string res = s;
        int l = left - radius;
        int r = right + radius;


        r++;
        while(r < len)
        {
            res = s[r] + res;
            r++;
        }
        return res;
    }
};
*/

/* manacher */
#define encode(i,j) ((i)+(j))

class Solution {
private:
    int id;
    int res1, res2;
    int Max = INT_MIN;
    int mx;

    void helper(int fir, int sec, vector<int>& p, string& s)
    {

        int cur =encode(fir, sec);
 
        if(sec < mx)
            p[cur] = min(p[2*id - cur],mx-sec);
        else    
            p[cur] = fir == sec;

        //cout << (fir-p[cur] >= 0 && sec+p[cur] < int(s.size()) && s[fir-p[cur]] == s[sec+p[cur]]) <<endl;
        while(fir-p[cur] >= 0 && sec+p[cur] < int(s.size()) && s[fir-p[cur]] == s[sec+p[cur]]) 
            p[cur]++;
        p[cur]--;
        

        if(fir - p[cur] == 0 && Max < (2 * p[cur] + 1 + (fir != sec)))
        {
            Max = 2 * p[cur] + 1 + (fir != sec);
            res1 = fir;
            res2 = sec;
        } 
        if(sec + p[cur] > mx)
        {
            mx = sec + p[cur];
            id = encode(fir,sec);
        }
    }
public:
    string shortestPalindrome(string s) {
        if(s.empty())   return s;
        //cout << s.size() <<endl;
        res1=res2=0;
        id=0;
        mx=0;
        vector<int> p(s.size() + 2, 0);

        for(int i = 0; i <= s.size()/2; i++)
        {
            helper(i, i, p, s);
            helper(i, i+1, p, s);
        }
        int i = res2 + p[encode(res1, res2)]+1;

        string res = s.substr(i, s.size() - i);
        reverse(res.begin(), res.end());
    
        return res + s;
    }
};


/* KMP */

class Solution {
private:
    void getRecord(string& s, vector<int> & record)
    {
        for(int i = 1; i < s.size(); i++)
        {
            int cur = record[i-1];
            while(cur > 0 && s[i] != s[cur])
                cur = record[cur-1];
            record[i] = cur + s[i] == s[cur];
        }
    }
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int i = 0;  //指示字符串s
        int j = 0;  //指示字符串t
        vector<int> record(s.size(), 0);
        getRecord(s, record);

        while(j < t.size())
        {
            
            while((j+i) < t.size() && s[i] == t[j+i])
                i++;

            if((j+i) == t.size())   
                break;
            
            j = max(j+1,j + i - (i > 0 ? record[i-1] : 0));
            i = i > 0 ? record[i-1] : 0;

        }

        return t.substr(0, j) + s; 

    }
};
