class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int greater = 0, less = 0;
        for(int i : nums)   
            greater += i;

        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); greater -= nums[i], less += nums[i], i++)
            ans[i] = (i * nums[i] - less) + (greater - (nums.size() - i) * nums[i]);

        return ans;
    }
};