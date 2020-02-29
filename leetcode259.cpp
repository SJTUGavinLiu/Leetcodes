
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() <= 2)    return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            int cnt = 0;
            while(l < r)
            {   
                if(nums[i]+nums[l]+nums[r] < target)
                {
                    cnt += (r-l);
                    l++;
                }
                else
                    r--;
            }   
            if(cnt == 0)
                break;
            res += cnt;
        }
        return res;
    }
};






class Solution {

int comb(int n, int m)
{
    if(n < m)   return 0;
    else if(n == m)  return 1;
    long long res = 1;
    for(int i = n; i >= (n-m+1); i--)
        res *= i;
    for(int i = 2; i <= m; i++)
        res /= i;
    return res;
}

public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() <= 2)    return 0;
        int i = 2;
        sort(nums.begin(), nums.end());
        int res = 0;
        while(i < nums.size())
        {
            if(nums[i-2]+nums[i-1]+nums[i] >= target)
                break;
            i++;            
        }
        cout << i << endl;
        res += comb(i, 3);
        if(i == nums.size())    return res;
        target -= nums[i];
        int tmp = i;
        i--;
        while(i >= 1)
        {
            if(nums[i] + nums[i-1] < target)
                break;
            i--;
        }
        i++;
        cout << i << endl;
        res += comb(i, 2);
        if(tmp == i)
            return res;
        
        target -= nums[i];
        i--;
        while(i >= 0)
        {
            if(nums[i] < target)   break;
            i--;
        }
        cout << i << endl;
        res += (i+1);

        return res;

    }
};