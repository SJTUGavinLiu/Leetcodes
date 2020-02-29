class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> nums(10, 0);
        int mod0 = 0;
        int mod1 = 0;
        int mod2 = 0;

        for(auto& digit: digits)
        {
            nums[digit]++;
            if(digit % 3 == 0)  mod0++;
            else if(digit % 3 == 1) mod1++;
            else    mod2++;
        }

        int mod12 = min(mod1,mod2);
        int new_mod1 = mod1 - (mod1-mod12) % 3;
        int new_mod2 = mod2 - (mod2-mod12) % 3;
        if(mod1 > mod2 && (mod1 - mod12) % 3 == 2 && new_mod2)
        {
            new_mod2--;
            new_mod1+=2;
        }
        else if(mod1 < mod2 && (mod2 - mod12) % 3 == 2 && new_mod1)
        {
            new_mod1--;
            new_mod2+=2;
        }

        int i = 9;



        string res = "";
        while(i >= 0)
        {

            if(nums[i])  
            {
                if(i % 3 == 0)
                    res = res + string(nums[i], '0'+i);    
                else if(i % 3 == 1)
                {
                    res += string(max(0, min(nums[i], new_mod1)), '0'+i);
                    new_mod1 -= nums[i];
                }
                else
                {
                    res += string(max(0, min(nums[i], new_mod2)), '0'+i);
                    new_mod2 -= nums[i];
                }
 
            }  
            i--;
 
        }
        if(res[0] == '0')   return "0";
        return res;


    }
};