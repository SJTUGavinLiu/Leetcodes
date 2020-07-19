class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> dict;
        for(auto& num: nums1)
        {
            if(!dict.count(num))
                dict[num] = {1, 0};
            else
                dict[num].first++;
        }
        
        for(auto& num: nums2)
        {
            if(dict.count(num))
                dict[num].second++;
        }

        vector<int> res;
        for(auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            for(int i = 0; i < min(iter->second.first, iter->second.second); i++)
                res.push_back(iter->first);
        }
        return res;
    }
};