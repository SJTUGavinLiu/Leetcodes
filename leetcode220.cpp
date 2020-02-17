class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long>  Set;
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = Set.lower_bound(nums[i]-long(t));
            if(iter != Set.end() && *iter <= nums[i] + long(t))   return true;
            Set.insert(nums[i]);
            if(Set.size()>k)    Set.erase(nums[i-k]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
    }
};