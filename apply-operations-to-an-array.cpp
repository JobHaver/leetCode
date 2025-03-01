class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            if(nums[i-1] == nums[i])
                nums[i-1] *= 2, nums[i] = 0;

        for(int i = 0, currZero = 0; i < nums.size(); currZero++){
            for(; currZero < nums.size() && nums[currZero] != 0; currZero++);
            for(i = max(i, currZero + 1); i < nums.size() && nums[i] == 0; i++);

            if(i < nums.size())
                swap(nums[i], nums[currZero]);
        }

        return nums;
    }
};