struct node {
    int val;
    node *next;
    node(int v, node *n) : val{v}, next{n} {}
};

class MyStack {
public:
    node *t;
    deque<int> q;

    MyStack() {
        t = NULL;
    }
    
    void push(int x) {
        t = new node(x, t);
        // q.push_back(x);
    }
    
    int pop() {
        node *temp = t;
        t = t->next;
        int val = temp->val;
        delete(temp);
        return val;
        
        // int temp = q.back();
        // q.pop_back();
        // return temp;
    }
    
    int top() {
        return t->val;
        //return q.back();
    }
    
    bool empty() {
        return !t;
        //return q.empty();
    }

    ~MyStack(){
        for(node *temp; t; delete(temp))
            temp = t, t = t->next;
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