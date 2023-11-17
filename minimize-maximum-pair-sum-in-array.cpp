class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = -1;
        for(int l = 0, r = nums.size() - 1; l < r; l++, r--)
            max = std::max(nums[l] + nums[r], max);
        
        return max;
    }
};