class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true, decrease = true;

        for(int i = 1; i < nums.size() && (increase || decrease); i++){
            if(increase)
                increase = nums[i] <= nums[i-1];
            if(decrease)
                decrease = nums[i] >= nums[i-1];
        }

        return increase || decrease;
    }
};