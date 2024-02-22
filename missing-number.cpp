class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual = 0, expected = nums.size();
        for(int i = 0; i < nums.size(); expected += i++)
            actual += nums[i];

        return expected - actual;
    }
};