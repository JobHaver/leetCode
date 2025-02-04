class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], currSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] < nums[i])
                ans = max(ans, currSum += nums[i]);
            else
                currSum = nums[i];
        }

        return ans;
    }
};