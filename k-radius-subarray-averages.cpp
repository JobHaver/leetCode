class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        long long total = 0;
        int diameter = k*2 + 1, dSize = diameter-1;

        for(int i = 0; i < dSize && i < nums.size(); i++){ // innit
            total += nums[i];
        }

        for(int i = 0, j = dSize; j < nums.size(); i++, k++, j++){
            total += nums[j];
            ans[k] = total / diameter;
            total -= nums[i];
        }

        return ans;
    }
};