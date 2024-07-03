class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3)
            return 0;

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int l = 0, r = nums.size()-4; l < 4; l++, r++)
            ans = min(ans, nums[r] - nums[l]);

        return ans;
    }
};