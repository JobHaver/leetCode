class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int curr = nums[0];

        for(int i = 1; i < nums.size(); i++)
            curr ^= nums[i];

        return __builtin_popcount(curr ^ k);
    }
};