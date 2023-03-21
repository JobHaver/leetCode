class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 1;

        for(const int n : nums){
            if(!n)
                ans += zeros++;
            else
                zeros = 1;
        }

        return ans;
    }
};