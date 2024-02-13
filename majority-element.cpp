class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i : nums)
            count[i]++;

        int ans, half = nums.size() / 2;
        for(auto &p : count)
            if(p.second > half)
                return p.first;
    
        return -1;
    }
};