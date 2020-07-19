

void print(vector<int>& arr)
{
    for(auto& item: arr)
        cout << item << '/t';
    cout << endl;
}


class ArrayTree {
private:
    vector<int> value;
    vector<int> tree;
    int lowBit(int x) {
        return x & (-x);
    }
    int getId(int x) {
        return lower_bound(value.begin(), value.end(), x) - value.begin() + 1;
    }
public:
    ArrayTree(vector<int>& nums) {
        value.assign(nums.begin(), nums.end());
        sort(value.begin(), value.end());
        value.erase(unique(value.begin(), value.end()), value.end());
        tree.resize(nums.size() * 2, 0);
    }
    
    int query(int num) {
        int pos = getId(num) - 1;
        int res = 0;

        while(pos > 0) {
            res += tree[pos];
            pos -= lowBit(pos);
        }
        return res;

    }
    void update(int num) {
        int pos = getId(num);
        while(pos < tree.size())
        {
            tree[pos] += 1;
            pos += lowBit(pos);
        }
    }


};



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ArrayTree arrayTree(nums);
        vector<int> res(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; i--)
        {
            res[i] = arrayTree.query(nums[i]);
            arrayTree.update(nums[i]);
        }
        return res;
    }
};