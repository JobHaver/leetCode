class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> costs = nums;
        int i = 0;
        for(int size = nums.size() - 3; i < size; i++){
            if(costs[i] + nums[i+2] > costs[i+2])
                costs[i+2] = costs[i] + nums[i+2];

            if(costs[i] + nums[i+3]  > costs[i+3])
                costs[i+3] = costs[i] + nums[i+3];
        }

        if(i + 2 < nums.size() && costs[i] + nums[i+2] > costs[i+2])
            costs[i+2] = costs[i] + nums[i+2];

        return nums.size() == 1 ? costs[0] : max(costs[costs.size()-1], costs[costs.size()-2]);
    }
};