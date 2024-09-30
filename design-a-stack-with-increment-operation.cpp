class CustomStack {
private:
    vector<int> stack;
    int curr;

public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        curr = 0;
    }
    
    void push(int x) {
        if(curr == stack.size())
            return;

        stack[curr++] = x;
    }
    
    int pop() {
        return curr == 0 ? -1 : stack[--curr];
    }
    
    void increment(int k, int val) {
        for(int i = 0, max = min(k, curr); i < max; i++)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */