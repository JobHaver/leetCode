class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int max = 0, j = nums.size(), prev = -1;
        for(int i = nums.size()-1; i >= 0 && j; i--){
            if(nums[i] == prev)
                continue;
            int target = nums[i], ops = k, count = 1;
            for(j = i - 1; j >= 0; j--){
                ops -= target - nums[j];
                if(ops < 0)
                    break;
                count++;
            }

            prev = target;
            max = std::max(count, max);
        }

        return max;
    }
};