class RandomizedSet {
private:
    int count;
    unordered_map<int, bool> m;

public:
    RandomizedSet() {
        count = 0;
        m.clear();
    }
    
    bool insert(int val) {
        bool &v = m[val];
        if(v)
            return false;
        
        count++;
        return v = true;
    }
    
    bool remove(int val) {
        bool v = m[val];
        if(v)
            count--;

        m.erase(val);
        return v;
    }
    
    int getRandom() {
        int r = rand() % count, i = 0;
        for(auto &p : m){
            if(r == i++)
                return p.first;
        }

        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */