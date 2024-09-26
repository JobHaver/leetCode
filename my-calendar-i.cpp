class MyCalendar {
private:
    map<int, int> m;

public:
    bool book(int start, int end) {
        auto p = m.upper_bound(start);

        if(p != m.end() && p->second < end)
            return false;
        
        m[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */