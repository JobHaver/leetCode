class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int total = 0, max = 0, min = 0;
        for(int i : nums){
            total += i;
            if(total < min)
                min = total;
            else if(total > max)
                max = total;
        }

        return abs(min) + max;
    }
};