#include<vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size()-1;
        if(len==-1) return -1;
        int beg = 0, end = len;
        int mid;
        if(nums[0]<nums[len])
        {
            
            while(beg<=end)
            {
                mid=(beg+end)/2;
                if(nums[mid] > target)
                    end = mid-1;
                else if(nums[mid] < target)
                    beg = mid+1;
                else
                    return mid;
            }
        }
        
        if(target>=nums[0])  
        {
            if(target==nums[0]) return 0;
            while(beg<=end)
            {
                mid=(beg+end)/2;
                if(nums[mid]<=nums[len] || nums[mid]>target)
                    end= mid-1;
                else if(nums[mid]<target)
                    beg=mid+1;
                else if(nums[mid]==target)
                    return mid;
            }
            
        }
        else if(target<=nums[len])
        {
            if(target==nums[len]) return len;
            while(beg<=end)
            {
                mid=(beg+end)/2;
                if(nums[mid]>=nums[0] || nums[mid]<target)
                    beg= mid+1;
                else if(nums[mid]>target)
                    end=mid-1;
                else if(nums[mid]==target)
                    return mid;
            }
            
        }
        
        return -1;
    }
};

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        return helper(nums,target,0,nums.size()-1);
    }

    int helper(vector<int>& nums, int target, int beg, int end)
    {
        
        if(nums[beg] == target) return beg;
        else if(nums[end] == target)    return end;
        if(beg >= end)   return -1;

        int mid;
        if(nums[beg]<=nums[end])
        {
            if(target < nums[beg] || target > nums[end])    return -1;
            mid = (beg+end)/2;
            if(beg == mid)  return -1;
            if(target == nums[mid])   return mid;
            else if(target < nums[mid]) return helper(nums,target,beg,mid);
            else if(target > nums[mid]) return helper(nums,target,mid,end);
        }
        else
        {
            mid = (beg+end)/2;
            if(beg == mid)  return -1;
            if(target == nums[mid])   return mid;
            else if(target > nums[beg])  return helper(nums,target,beg,mid);
            else if(target < nums[end]) return helper(nums,target,mid,end);
        }
        return -1;
    }
};
*/