class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());

        int i = 0, j = nums.size() - 1;
        for(int n : nums){
            if(n % 2 == 0)
                ans[i++] = n;
            else
                ans[j--] = n;
        }

        return ans;
    }
};