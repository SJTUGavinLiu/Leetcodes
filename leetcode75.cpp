class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1;
        int white = -1;
        int blue = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                red++;
                white++;
                blue++;
                nums[red] = 0;
                if(red != white)
                {
                    nums[white] = 1;
                }
                if(white != blue)
                {
                    nums[blue] = 2;
                }
            }
            else if(nums[i] == 1)
            {
                white++;
                blue++;
                nums[white] = 1;
                if(white != blue)
                {
                    nums[blue] = 2;
                }
            }
            else{
                blue++;
                nums[blue] = 2;
            }
        }
    }
};