class SmallestInfiniteSet {
public:
    int max;
    // std::priority_queue<int, std::vector<int>, std::greater<int>> out;
    std::priority_queue<int, std::vector<int>, std::greater<int>> in;

    SmallestInfiniteSet() : max{1} {}
    
    int popSmallest() {
        if(in.empty())
            return max++;
           
        int temp = in.top();
        while(!in.empty() && in.top() == temp) //get rid of duplicates
            in.pop();
        
        return temp;
    }
    
    void addBack(int num) {
        if(num < max)
            in.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */