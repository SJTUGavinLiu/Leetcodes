#include<vector>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0)   return (nums2[nums2.size()/2]+nums2[(nums2.size()-1)/2])/2.0;
        if(nums2.size() == 0)   return (nums1[nums1.size()/2]+nums1[(nums1.size()-1)/2])/2.0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        nums1.insert(nums1.begin(),INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.insert(nums2.begin(),INT_MIN);
        nums2.push_back(INT_MAX);
        
        int pos1 = (len+1)/2;
        int pos2 = (len+2)/2;
        
        int i = (len1+1)/2;
        int j = pos1 - i;
        if(nums1[i] > nums2[j+1])
        {
            while(nums1[i] > nums2[j+1])
            {
                i--;
                j++;
            }
        }
        else if(nums2[j] > nums1[i+1])
        {
            while(nums2[j] > nums1[i+1])
            {
                i++;
                j--;
            }
        }
        if(i == 0 && j == len2+1)  return (nums1.front()+nums2.back())/2.0;
        else if(j == 0 && i == len1+1)  return (nums1.back()+nums2.front())/2.0;
        //else if(i == 0) return (nums2[pos1] + nums2[pos2])/2.0;
        //else if(j == 0) return (nums1[pos1] + nums1[pos2])/2.0;
        else
        {                                                                                                                 if(pos1 == pos2) return max(nums1[i],nums2[j]);
            else    return (max(nums1[i],nums2[j])+min(nums1[i+1],nums2[j+1]))/2.0;
        }
        return 0;
    }
};