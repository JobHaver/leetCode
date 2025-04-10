class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] < k)
            return -1;

        int ans = 0, prev, i;
        for(i = nums.size() - 1, prev = nums[i]; i >= 0; prev = nums[i--])
            if(prev != nums[i])
                ans++;

        return prev == k ? ans : ans + 1;
    }
};