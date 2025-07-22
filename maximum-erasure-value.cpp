class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr = 0, ans = 0;
        unordered_map<int, int> mp;

        for(int i = 0, j = 0; i < nums.size(); i++){
            curr += nums[i];
            if(mp[nums[i]]++){
                while(nums[j] != nums[i]){
                    curr -= nums[j];
                    mp[nums[j++]]--;
                }

                curr -= nums[j];
                mp[nums[j++]]--;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};