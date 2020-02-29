class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        int i = (len-1)/2;
        int j = len/2;
        unordered_map<char, char> dict {{{'6','9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}}, 5};
        
        while(i >=0 && j < len)
        {
            if(!dict.count(num[i]))    return false;
            if(dict[num[i]] != num[j])  return false;
            i--;j++;
        }
        return true;

    }
};