class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0;
        int j = 0;
        int num1 = 0;
        int num2 = 0;
        while(i < version1.size() || j < version2.size())
        {
            while(i < version1.size() && version1[i] != '.')
            {
                num1 = 10 * num1 + version1[i] - '0';
                i++;
            }
            i++;
            while(j < version2.size() && version2[j] != '.')
            {
                num2 = 10 * num2 + version2[j] - '0';
                j++;
            }
            j++;
            if(num1 > num2) return 1;
            else if(num1 < num2)    return -1;
            num1 = 0;
            num2 = 0;
        }
        return 0;
    }
};