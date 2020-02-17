#include<vector>
#include<string>
#include<iostream>
using namespace std;

#define encode(i, j) ((i)+(j))


class manacher {
private:
    int id;
    int mx;
    int Max;
    void helper(int fir, int sec, vector<int>& p, string& s)
    {
        int cur = encode(fir, sec);
        if(sec < mx)
            p[cur] = min(p[2*id - cur],mx-sec);
        else    
            p[cur] = fir == sec;
        while(fir-p[cur] >= 0 && sec+p[cur] < s.size() && s[fir-p[cur]] == s[sec+p[cur]]) 
            p[cur]++;
        p[cur]--;

        Max = max(Max, 2*p[cur]+1+(fir!=sec));
        if(sec + p[cur] > mx)
        {
            mx = sec + p[cur];
            id = encode(fir,sec);
        }
    }


public:
    manacher() {}
    int algo(string text)
    {
        vector<int> p(text.size()*2, 0);
        id = 0;    
        mx = 0;
        Max = 0;

        for(int i = 0; i < text.size(); i++)
        {
            helper(i,i,p,text);
            helper(i,i+1,p,text);
        }
        return Max;
    }

};



int main()
{
    manacher obj;
    cout << obj.algo("abbabhcbapbchopxo");
}