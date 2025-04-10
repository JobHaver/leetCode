class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //looking at other solutions a better way to go about this is to check from the back as you would only have to find the first copy and delete to there
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        for(; i < nums.size(); i++)
            if(mp[nums[i]]++)
                while(j < nums.size())
                    if(--mp[nums[j++]])
                        break;

        return j / 3 + (j % 3 == 0 ? 0 : 1);
    }
};