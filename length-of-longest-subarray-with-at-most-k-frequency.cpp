class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, short> mp;
        int ans = 0, curr = 0;

        k++; //done so dont use <= op
        for(int l = 0, r = 0; r < nums.size(); r++){
            if(++mp[nums[r]] < k)
                ans = max(ans, ++curr);
            else
                for(; mp[nums[l]]-- && nums[l++] != nums[r]; curr--);
        }

        return ans;
    }
};