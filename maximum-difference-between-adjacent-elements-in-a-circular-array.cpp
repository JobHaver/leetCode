class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max = 0;

        for(int i = 1; i < nums.size(); i++)
            max = std::max(max, abs(nums[i-1] - nums[i]));
            
        return std::max(max, abs(nums[0] - nums[nums.size()-1]));
    }
};