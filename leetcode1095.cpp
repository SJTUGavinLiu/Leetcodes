/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0;
        int r = len - 1;
        int peek=-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            //cout << l << '\t' << r << '\t';
            if(mid == 0) { l = 1; continue;}
            else if(mid == (len - 1)) { r = len - 2; continue; }
            int left = mountainArr.get(mid-1);
            int cur = mountainArr.get(mid);
            int right = mountainArr.get(mid+1);
            //cout << left << '\t' << cur << '\t' << right << endl;
            if(left < cur && cur > right)  
            {
                peek = mid;
                if(cur == target)   return peek;
                break;
            }
            else if(cur < right)
                l = mid+1;
            else if(left > cur)
                r = mid-1;
        }
        //cout << peek << endl;
        l = 0;
        r = peek-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int cur = mountainArr.get(mid);
            if(cur == target) return mid;
            else if(cur > target) r = mid-1;
            else if(cur < target) l = mid + 1;
        } 
        l = peek+1;
        r = len-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int cur = mountainArr.get(mid);
            if(cur == target) return mid;
            else if(cur < target) r = mid-1;
            else if(cur > target) l = mid + 1;
        } 
        return -1;
    }
};