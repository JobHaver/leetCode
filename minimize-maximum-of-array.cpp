class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int max = 0;
        double avg = 0;
        for(int i = 0; i < nums.size(); i++){
            avg = ((avg * i) / (i+1.0)) + (nums[i] / (i+1.0));
            if(avg > max)
                max = ceil(avg);
        }

        return max;
    }
};