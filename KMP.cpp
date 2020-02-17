#include<string>
#include<vector>
#include<iostream>
using namespace std;

class KMP {
private:
    void get_pre_post_len(string s, vector<int>& record)
    {
        record[0] = 0; //单字符字符串没有公共前后缀

        for(int i = 1; i < s.size(); i++)
        {
            int j = record[i-1];
            while(s[j] != s[i] && j > 0)
                j = record[j-1];
            record[i] = j + (s[j] == s[i]);
        }
        //for(int i = 0; i < s.size(); i++)
        //    cout << record[i] << '\t';

    }
public:
    KMP() {}
    bool kmp(string text, string target)
    {
        vector<int> record(target.size(), 0);
        get_pre_post_len(target, record);

        int i = 0; 
        int j = 0;
        while((i+target.size()) <= text.size())
        {
            while(j < target.size())
            {
                if(target[j] != text[i+j])
                {
                    i = i + j - record[j-1];
                    j = record[j-1];
                    break;
                }
                j++;
            }
            if(j == target.size())
                return true;
        }
        return false;
    }

};

int main()
{
    KMP obj;
    string target = "abaabbabaab";
    string text = "abaabaabbabaaabaababaab";
    cout << obj.kmp(text, target);
}