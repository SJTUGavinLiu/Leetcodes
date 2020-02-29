class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 1;
        int count1 = 0, count2 = 0;
        for(auto& num: nums)
        {
            if(count1 == 0)
            {
                num1 = num;
                count1 = 1;
            }
            else if(num == num1)
            {
                count1++;
            }
            else if(count2 == 0)
            {
                num2 = num;
                count2 = 1;
            }
            else if(num == num2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
                if(count1 == 0 && count2 > 0)
                {
                    count1 = count2;
                    num1 = num2;
                    count2 = 0;
                }
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto& num: nums)
        {
            if(num == num1) count1++;
            else if(num == num2) count2++;
        }
        vector<int> res;
        if(count1*3 > nums.size())  res.push_back(num1);
        if(count2*3 > nums.size())  res.push_back(num2);
        return res;
        
    }
};