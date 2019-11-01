
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        if(height.empty())  return 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[0];
        int right_max = height.back();
        int res = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] < left_max)
                    res += (left_max - height[left]);
                else
                    left_max = height[left];
                left++;

            }
            else
            {
                if(height[right] < right_max)
                    res += (right_max - height[right]);
                else 
                    right_max = height[right];
                right--;
            }
        }   
        return res;

    }
};
