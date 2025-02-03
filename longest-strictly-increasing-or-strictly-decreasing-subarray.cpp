class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, incCount = 1, decCount = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                incCount = 1, decCount = 1;
            else if(nums[i] > nums[i-1])
                ans = max(ans, ++incCount), decCount = 1;
            else
                ans = max(ans, ++decCount), incCount = 1;
        }

        return ans;
    }
};