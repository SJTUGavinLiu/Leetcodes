class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int j = (nums.size()-1) / 2 + 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i+=2)
        {
            //cout<< i << '\t' << j << endl;
            swap(nums[i], nums[j++]);
        }
            
    }
};