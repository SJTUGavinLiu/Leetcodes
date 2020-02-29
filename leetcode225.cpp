class MyStack {
private:
    int idx;
    int* stack;
    int maxLen;
    void doubleSpace()
    {
        //cout << maxLen << endl;
        int* new_stack = new int[maxLen*2];
        for(int i = 0; i < maxLen; i++)
            new_stack[i] = stack[i];
        maxLen *= 2;
        delete [] stack;
        stack = new_stack;
    }
public:
    /** Initialize your data structure here. */
    MyStack() {
        idx = 0;
        maxLen = 10;
        stack = new int[maxLen];
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(idx == maxLen)
            doubleSpace();
        stack[idx++] = x;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return stack[--idx];
    }
    
    /** Get the top element. */
    int top() {
        return stack[idx-1];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return idx == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */