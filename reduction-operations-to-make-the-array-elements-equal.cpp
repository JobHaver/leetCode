class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ops = 0, prev = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] == prev)
                continue;
            
            ops += nums.size() - 1 - i;
            prev = nums[i];
        }

        return ops;
    }
};