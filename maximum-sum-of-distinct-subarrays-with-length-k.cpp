class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < k)
            return 0;

        unordered_map<int, int> m;
        int conflicts = 0;
        long long ans = 0;
        long long curr = 0;

        for(int i = 0; i < k; curr += nums[i++])
            if(++m[nums[i]] > 1)
                conflicts++;
        
        for(int i = k; i < nums.size(); i++){
            if(!conflicts)
                ans = max(curr, ans);

            if(--m[nums[i - k]])
                conflicts--;
            if(++m[nums[i]] > 1)
                conflicts++;
            curr += nums[i] - nums[i - k];
        }

        return !conflicts ? max(curr, ans) : ans;
    }
};