class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int size = nums.size();

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != key)
                continue;

            int j = max(i - k, 0);
            if(!ans.empty())
                j = max(ans.back() + 1, j);

            int goal = min(i + k + 1, size);
            for(; j < goal; j++)
                ans.push_back(j);
        }

        return ans;
    }
};