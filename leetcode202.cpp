class Solution {
public:
    bool isHappy(int n) {
        if(n==0)    return false;
        unordered_set<int> s;
        
        while(n)
        {
            //cout << n << endl;
            if(n == 1)  break;
            if(s.count(n))
                return false;
            s.insert(n);
            int next = 0;
            while(n)
            {
                int cur = n % 10;
                next += cur * cur;
                n /= 10;
            }   
            n = next;
            
        }
        return true;      
    }
};