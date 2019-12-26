class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = 0;
        for(int x: nums2)
        {
            while(1)
            {
                if(p == m || x <= nums1[p])
                {

                    for(int i = m-1; i >= p; i--)
                    {
                        nums1[i+1] = nums1[i];
                    }
                    nums1[p] = x;  
                    m++;
                    p++;
                    break;
                }
                p++;
            }
        
        }

    }
};