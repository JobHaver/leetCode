class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> minNums(nums.size());
        int currMin = INT_MAX;
        for(int i = nums.size()-1; i >= 0; i--)
            minNums[i] = currMin = min(currMin, nums[i]);

        int minValue = k + 1, currMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currMax = max(currMax, nums[i]);
            if(currMax - minNums[i] >= minValue)
                continue;
            
            return i;
        }

        return -1;
    }
};