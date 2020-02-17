class TwoSum {
private:
    unordered_map<int, int> dict;
    vector<int> container;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if(dict.count(number))
        {
            dict[number]++;
        }
        else
        {
            dict[number] = 1;
            container.push_back(number);
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto& num: container)
        {
            dict[num]--;
            if(dict.count(value-num) && dict[value-num])
            {
                dict[num]++;
                return true;
            }
            dict[num]++;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */