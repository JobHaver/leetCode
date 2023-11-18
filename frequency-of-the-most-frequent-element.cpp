class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int max = 0;
        for(int i = nums.size()-1, j = i; i >= 0; i--){
            while(k - (nums[j] - nums[i]) < 0)
                k += (nums[j] - nums[j - 1]) * (--j - i); //diff * number of elements
            
            k -= nums[j] - nums[i];
            max = std::max(j - i, max);
        }

        return max + 1;
    }
};