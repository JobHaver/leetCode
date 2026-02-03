class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstNum = nums[0];
        sort(nums.begin(), nums.end());

        if(firstNum == nums[0])
            return firstNum + nums[1] + nums[2];
        else if(firstNum == nums[1])
            return nums[0] + firstNum + nums[2];
        
        return nums[0] + nums[1] + firstNum;
    }
};