#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid = binarySearch(nums,target,0,nums.size()-1);
        if(mid == -1)   return {-1, -1};
        int beg = mid - 1;
        int end = mid + 1;
        while(beg >= -1)
        {
            if(beg == -1 || nums[beg] != target){
                beg++;
                break;
            }
            beg--;
        }
        while(end <= int(nums.size()))
        {
            if(end == nums.size() || nums[end] != target){
                end--;
                break;
            }
            end++;
        }
        return {beg, end};
    }
    int binarySearch(vector<int>&nums,int target, int beg, int end){
        if(beg > end)   return -1;
        int mid = (beg+end)/2;
        if(target == nums[mid]) return mid;
        if(mid == beg)  return target == nums[end] ? end : -1;

        if(target < nums[mid]) return binarySearch(nums,target,beg,mid);
        else    return binarySearch(nums,target,mid,end);
    }

    int binarySearch(vector<int> &nums, int target, bool left){
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = (l+r) / 2;
            if(nums[mid] > target || (left && target == nums[mid]))     r = mid;
            else    l = mid;      
        }
        return l;
    }


};