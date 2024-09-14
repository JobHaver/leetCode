class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int currCount = 0, maxNumber = -1, ans = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxNumber)
                ans = max(++currCount, ans);
            else if(nums[i] > maxNumber){
                maxNumber = nums[i];
                currCount = 1;
                ans = 1;
            }
            else
                currCount = 0;
        }

        return ans;
    }
};