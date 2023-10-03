class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans = 0;

        for(int i : nums)
            ans += count[i]++;

        return ans;
    }
};