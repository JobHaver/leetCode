class Solution {
private:
    int rev(int n){
        int rn = 0, rem;

        while(n != 0) {
            rem = n % 10;
            rn = rn * 10 + rem;
            n /= 10;
        }

        return rn;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> diff;

        for(int i = 0; i < nums.size(); i++, ans %= 1000000007)
            ans += diff[nums[i] - rev(nums[i])]++;

        return ans;
    }
};