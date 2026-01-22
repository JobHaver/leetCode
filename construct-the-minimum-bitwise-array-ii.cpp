class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            int index = 0;
            while(temp & 0x01){
                index++;
                temp = temp >> 1;
            }
            
            ans[i] = index ? nums[i] - (0 ^ (1 << index-1)) : -1;
        }

        return ans;
    }
};