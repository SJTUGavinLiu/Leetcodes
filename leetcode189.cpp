class Solution {
public:
    void reverse(vector<int>& nums, int beg, int len)
    {
        int end = beg + len - 1;
        while(beg < end)
        {
            swap(nums[beg], nums[end]);
            beg++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums, 0, len);
        reverse(nums, 0, k);
        reverse(nums, k, len - k);       
    }
};