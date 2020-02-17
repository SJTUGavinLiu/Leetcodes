class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        priority_queue<int> qu;
        for(int i = 0; i < nums.size(); i++)
            qu.push(nums[i]);
        for(int i = 1; i < k; i++)
            qu.pop();
        return qu.top();
    }
};
class Solution {
public:
    int quickSelect(int beg, int end, int k, vector<int>& nums)
    {
        //cout << beg << '\t' << end << endl;
        int pivot = nums[beg];
        int i = beg;
        int j = end;
        while(i < j)
        {
            while(i < j && nums[j] >= pivot)
                j--;
            if(i < j)
                nums[i] = nums[j];

            while(i < j && nums[i] < pivot)
                i++;
            if(i < j)
                nums[j] = nums[i];            
        }
        nums[i] = pivot;
        // [i, end] end - i + 1 items which are no smaller than pivot
        // [beg, i) i - beg items which are greater than pivot
        int left = i - beg; 
        int right = end - i + 1;

        if(right < k)
            return quickSelect(beg, i-1, k - right, nums);
        else if(right == k)
            return pivot;
        else    
            return quickSelect(i+1, end, k, nums);
        

    }
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        return quickSelect(0,nums.size()-1,k, nums);
    }
};



/*
    non-recursive version
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int beg = 0;
        int end = nums.size()-1;

        while(beg <= end)
        {
            int pivot = nums[beg];
            int i = beg;
            int j = end;
            while(i < j)
            {
                while(i < j && nums[j] >= pivot)
                    j--;
                if(i < j)
                    nums[i] = nums[j];

                while(i < j && nums[i] < pivot)
                    i++;
                if(i < j)
                    nums[j] = nums[i];            
            }
            nums[i] = pivot;
            // [i, end] end - i + 1 items which are no smaller than pivot
            // [beg, i) i - beg items which are greater than pivot
            int left = i - beg; 
            int right = end - i + 1;

            if(right < k)
            {
                end = i-1;
                k = k - right;
            }
            else if(right == k)
                return pivot;
            else    
                beg = i+1;
        }
        return -1;
    }
};