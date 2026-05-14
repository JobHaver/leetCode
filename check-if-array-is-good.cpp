class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() < 2)
            return false;

        sort(nums.begin(), nums.end());
        for(int i = 0, size = nums.size()-1; i < size; i++)
            if(nums[i] != i+1)
                return false;

        return nums[nums.size()-1] == nums[nums.size()-2];
    }
};