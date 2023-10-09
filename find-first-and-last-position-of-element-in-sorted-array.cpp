class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if(it1 == nums.end() || *it1 != target)
            return {-1, -1};

        return {int(it1 - nums.begin()), int(upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1)};
    }
};