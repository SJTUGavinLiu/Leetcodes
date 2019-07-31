#include<vector>
#include<string>
using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int cur, res = 0;
        while(i<j)
        {
            cur = min(height[i],height[j]) * (j - i);
            res = res > cur ? res : cur;
            if(height[i] < height[j])   i++;
            else   j--; 
        }
        return res;
    }
};