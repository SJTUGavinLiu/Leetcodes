


/*
    基数排序
*/

class Solution {
private:
    int getIndex(int& num, int& exp)
    {
        return (num / exp) % 10;
    }
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int Max = INT_MIN; 
        for(auto& num: nums)
            Max = max(num, Max);
        int exp = 1;
        
        vector<int> tmp(nums.size(), 0);
        while(Max / exp)
        {
            vector<int> count(10,0);
            for(auto& num: nums)
            {
                count[getIndex(num, exp)]++;
            }
            for(int i = 1; i < 10; i++)
            {
                count[i] += count[i-1];
            }
            for(int i = nums.size() - 1; i >=0; i--)
            {
                tmp[--count[getIndex(nums[i], exp)]] = nums[i];
            }
            for(int i = 0; i < nums.size(); i++)
                nums[i] = tmp[i];

            exp *= 10;
        }

        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            res = max(res, nums[i+1] - nums[i]);
        }
        return res;

        
    }
};

/* 
    桶排序
*/

/* 
    桶排序
*/

class Solution {
private:
    int Max, Min;
    int bucketNum;
    int bucketSize;
    int getIndex(int& num)
    {
        return (num - Min) / bucketSize;
    }
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        Max = INT_MIN;
        Min = INT_MAX;
        for(auto& num: nums)
        {
            Max = max(Max, num);
            Min = min(Min, num);
        } 
        if(nums.size() == 2)    return Max-Min;
        bucketSize = (Max - Min) / (nums.size() - 1)+1;
        bucketNum = (Max - Min) / bucketSize;

        //cout << bucketSize << ' ' << bucketNum;
        vector<int> bucketMax(bucketNum+1, INT_MIN);
        vector<int> bucketMin(bucketNum+1, INT_MAX);

        for(auto& num: nums)
        {
            int idx = getIndex(num);
            bucketMax[idx] = max(bucketMax[idx], num);
            bucketMin[idx] = min(bucketMin[idx] ,num);
        }

        int pre = INT_MAX;
        int gap = 0;
        for(int i = 0; i <= bucketNum; i++)
        {
            if(bucketMax[i] == INT_MIN) continue;
            gap = max(gap, bucketMin[i] - pre);
            pre = bucketMax[i];
        }

        return gap;

    }
};