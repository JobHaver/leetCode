class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int currNum = k;

        for(int i = 0; i < nums.size(); i++){
            if(currNum < nums[i])
                return currNum;

            if(currNum == nums[i])
                currNum += k;
        }

        return currNum;
    }
};