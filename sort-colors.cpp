class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < nums.size(); j++)
                if(i == nums[j])
                    swap(nums[curr++], nums[j]);
    }
};