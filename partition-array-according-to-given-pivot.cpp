class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());

        int lessThanCount = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < pivot)
                ans[lessThanCount++] = nums[i];
        
        int greaterThanCount = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--)
            if(nums[i] > pivot)
                ans[greaterThanCount--] = nums[i];

        for(int i = lessThanCount; i <= greaterThanCount; i++)
            ans[i] = pivot;

        return ans;
    }
};