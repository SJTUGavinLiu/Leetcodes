class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> stack(int(heights.size()) + 1, -1);
        int top = 0;
        int height = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            height = heights[i];
            if(top == 0)
            {
                stack[top+1] = i;
            }
            else
            {
                if(height < heights[stack[top]])
                {
                    while(top != 0 && height < heights[stack[top]])
                    {
                        maxArea = max(maxArea, (i - stack[top-1] - 1) * heights[stack[top]]);
                        top--;
                    }
                }
                stack[top+1] = i;
            }
            top++;
        }

        while(top != 0)
        {
            maxArea = max(maxArea, (int(heights.size()) - stack[top-1] - 1) * heights[stack[top]]);
            top--;
        }

        return maxArea;
        

    }
};