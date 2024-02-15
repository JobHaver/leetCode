class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int long long ans = -1, curr = nums[0] + nums[1];
        for(int i = 2; i < nums.size(); curr += nums[i++])
            if(nums[i] < curr)
                ans = curr + nums[i];

        return ans;
    }
};