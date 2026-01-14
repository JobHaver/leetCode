class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int prev = -1, curr = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == prev || nums[i] == curr)
                return nums[i];

            prev = curr;
            curr = nums[i];
        }

        return nums[0];
    }
};