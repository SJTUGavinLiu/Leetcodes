class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(auto& s: strs)
        {
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == ',')
                    res = res + "$,";
                else 
                    res = res + s[i];
            }
            res = res + ",";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string tmp = "";
        int i = 0;
        while(i < s.size())
        {
            
            if(s[i] == '$' && i+1 < s.size() && s[i+1] == ',')
            {
                tmp = tmp + ',';
                i+=2;
            }
            else if(s[i] == ',')
            {
                res.push_back(tmp);
                tmp.clear();
                i++;
            }
            else
                i++;

        }
        if(tmp != "")
            res.push_back(tmp);
        return res;
    }
};