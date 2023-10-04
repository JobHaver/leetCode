class MyHashMap {
public:
    unordered_map<int, int> map;

    MyHashMap() {
        map.clear();
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
            return -1;
        else
            return map[key];
    }
    
    void remove(int key) {
        map.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */