/*
    Solution 1
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            sum += (gas[i] - cost[i]);
        }   
        if(sum < 0) return -1;
        for(int i = 0; i < len; i++)
        {
            if(gas[i] < cost[i])    continue;
            int j;
            sum = gas[i] - cost[i];
            for(j = (i+1) % len; j != i; j = (j+1) % len)
            {
                sum = sum + gas[j] - cost[j];
                if(sum < 0) break;
            }
            if(j == i)
                return i;
        }
        return -1;
    }
};


/* 
    Solution 2
    一次遍历
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(len == 0) return -1;
        int cur = 0;
        int sum = 0;
        int pos = 0;
        for(int i = 0; i < len; i++)
        {
            if(cur == 0)    pos = i; 
            sum += (gas[i] - cost[i]);
            cur += (gas[i] - cost[i]);
            if(cur < 0) cur = 0;
        }   
        return sum >= 0 ? pos : -1;
        
    }
};