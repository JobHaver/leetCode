class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0, size = nums.size() - 2; i < size; i++){
            if(!nums[i]){
                ans++;
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
            }
        }

        if(nums[nums.size()-1] && nums[nums.size()-2] && nums[nums.size()-3])
            return ans;

        return -1;
    }
};