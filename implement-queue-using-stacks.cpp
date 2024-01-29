class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}
    
    void push(int x) {
        s2.push(x);
    }
    
    int pop() {
        int var = peek();
        s1.pop();
        return var;
    }
    
    int peek() {
        if(s1.empty()){
            for(; !s2.empty(); s2.pop())
                s1.push(s2.top());
        }

        return s1.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};