class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size() + 1, i = 0, j = 0, tot = 0;

        while(i < nums.size()){
            while(i < nums.size() && tot < target)
                tot += nums[i++];
            
            while(tot >= target)
                tot -= nums[j++];

            min = std::min(min, i + 1 - j);
        }

        return min > nums.size() ? 0 : min;
    }
};