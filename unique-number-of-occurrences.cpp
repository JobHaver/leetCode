class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int i : arr)
            count[i]++;

        unordered_map<int, int> dup;
        for(auto &p : count)
            if(dup[p.second]++) return false;
        
        return true;
    }
};