class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;

        for(int i : nums)
            sum += i;

        return sum & 1 ? 0 : nums.size()-1;

        // int totalL = 0, totalR = 0, ans = 0;

        // for(int i : nums)
        //     totalR += i;

        // for(int i = 0, size = nums.size()-1; i < size; i++){
        //     totalL += nums[i];
        //     totalR -= nums[i];

        //     if(((totalL - totalR) & 1) == 0)
        //         ans++;
        // }

        // return ans;
    }
};