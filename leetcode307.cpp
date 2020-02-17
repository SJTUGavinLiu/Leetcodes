vsclass NumArray {
    int* Tree;
    int N;
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        Tree = new int[N * 4];
        build(nums, 1, 0, N-1);

    }

    void update(int i, int val) {
        helper1(1, 0, N-1, i, val);
    }
    
    int sumRange(int i, int j) {
        return helper2(1, 0, N-1, i, j);
    }
    void build(vector<int>& nums, int node, int l, int r) {
        if(l > r)
        {
            return;
        }
        else if(l == r)
        {
            Tree[node] = nums[l];
        }
        else
        {
            int mid = (l+r)/2;
            build(nums, 2*node, l, mid);
            build(nums, 2*node+1, mid+1, r);
            Tree[node] = Tree[2*node] + Tree[2*node+1];
        }
    }
    
    void helper1(int node, int l, int r, int pos, int val)
    {
        if(l == r)
        {
            Tree[node] = val;
        }
        else
        {
            int mid = (l+r)/2;
            if(pos <= mid)
                helper1(2*node, l, mid, pos, val);
            else    
                helper1(2*node+1, mid+1, r, pos, val);
            Tree[node] = Tree[2*node] + Tree[2*node+1];
        }
    }

    int helper2(int node, int nl, int n, int l, int r)
    {
        if(l > r)   return 0;
        else if(l == nl && r == nr)
            return Tree[node];
        
      int mid = (nl + nr) / 2;
        return helper2(2*node, nl, mid, l, min(r,mid)) + helper2(2*node+1, mid+1, nr, max(mid+1, l), r);
 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */