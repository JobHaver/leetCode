class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
            return {};

        vector<string> ans;
        int start = nums[0], end = nums[nums.size()-1];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] + 1 != nums[i]){
                ans.push_back(start == nums[i-1] ? to_string(start) : to_string(start) + "->" + to_string(nums[i-1]));

                start = nums[i];
            }
        }

        ans.push_back(start == end ? to_string(end) : to_string(start) + "->" + to_string(end));

        return ans;
    }
};