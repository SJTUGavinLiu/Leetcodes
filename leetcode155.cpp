class MinStack {
public:
    /** initialize your data structure here. */
    int *data;
    int size_;
    int cur;
    MinStack() {
        data = new int[10];
        size_ = 10;
        cur = 0;
    }
    
    void push(int x) {
        if(cur == size_)    doubleSpace();
        data[cur++] = x;
        data[cur++] = min(x,cur-2>=0?data[cur-2]:INT_MAX);
    }
    
    void pop() {
        cur-=2;
    }
    
    int top() {
        return data[cur-2];
    }
    
    int getMin() {
        return data[cur-1];
    }
private:
    void doubleSpace()
    {
        int *tmp = new int[2*size_];
        for(int i = 0;i<size_;i++)
        {
            tmp[i] = data[i];
        }
        size_*=2;
        delete []data;
        data = tmp;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */