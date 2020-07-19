class Solution {
private: 
    vector<int> tmp;
public:
    int mergeSort(vector<int>& nums, int l, int r)
    {
        
        if(l >= r)  return 0; 
        int mid = (l + r) / 2;
        int sum = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r);
        int i = l, j = mid+1;

        int p = l;
        while(i <= mid)
        {
            while(j <= r && nums[i] > nums[j])
                tmp[p++] = nums[j++];
            
            tmp[p++] = nums[i];
            sum += (j - mid-1);
            i++;
        }
        for(int k = l; k <= r; k++)
            nums[k] = tmp[k];
        //cout << l << '\t' << r << '\t' << sum << endl;
        return sum;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1)    return 0;
        tmp = nums;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};