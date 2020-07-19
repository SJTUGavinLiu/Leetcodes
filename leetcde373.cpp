struct Node {
    int x;
    int y;
    Node(int x_, int y_): x(x_), y(y_) {}
}


bool cmp(Node* x, Node*y)
{
    return x->x + x->y < y->x + y->y;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0)  return {};
        vector<Node*> cont;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                cont.push_back(new Node(nums1[i], nums2[j]));
            }
        }
        sort(cont.begin(), cont.end(), cmp);
        vector<vector<int>> res;
        for(int i = 0; i < min(k, int(nums1.size()) * int(nums2.size())); i++)
            res.push_back({cont[i]->x, cont[j]->y});
        return res;
    }
};