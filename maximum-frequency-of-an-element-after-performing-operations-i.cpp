class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> mp;

        sort(nums.begin(), nums.end());

        for(int i : nums){
           mp[i - k]++;
           mp[i + k + 1]--;
        }

        int currOverlap = 0, i = 0, prev = -1, currDuplicates = 1, ans = 1;
        for(auto & [num, change] : mp){
            for(; i < nums.size() && nums[i] < num; i++){
                if(nums[i] == prev)
                    currDuplicates++;
                else
                    currDuplicates = 1;

                ans = std::max(ans, currDuplicates + min(currOverlap-currDuplicates, numOperations));
                prev = nums[i];
            }

            currOverlap += change;
            ans = std::max(ans, min(currOverlap, numOperations));
        }

        return ans;
    }
};