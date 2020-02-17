class Solution {
public:
    void reverse(vector<char>& s, int beg, int end)
    {
        while(beg < end)
        {
            swap(s[beg],s[end]);
            beg++;
            end--;
        }
    }
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        int beg = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(s,beg,i-1);
                beg = i+1;
            }
        }
        reverse(s, beg, s.size() - 1);

    }
};