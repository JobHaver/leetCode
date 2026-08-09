class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0, curr = nums[i]; i < nums.size(); curr++){
            if(nums[i] == curr)
                i++;
            else
                ans.push_back(curr);
        }
        
        return ans;
    }
};