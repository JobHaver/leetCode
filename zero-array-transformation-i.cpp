class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> changes(nums.size() + 1, 0);
        int currSubtraction = 0;

        for(int i = 0; i < queries.size(); i++){
            changes[queries[i][0]]++;
            changes[queries[i][1] + 1]--;
        }
            
        for(int i = 0, j = 0; i < nums.size(); i++)
            if((currSubtraction += changes[i]) < nums[i])
                return false;

        return true;
    }
};