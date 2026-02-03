class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1, prev = nums[i], start;

        for(start = i; i < nums.size() && nums[i] > nums[i-1]; i++);
        
        if(i >= nums.size() || i == start)
            return false;;

        for(start = i; i < nums.size() && nums[i] < nums[i-1]; i++);

        if(i >= nums.size() || i == start)
            return false;

        for(start = i; i < nums.size() && nums[i] > nums[i-1]; i++);

        return i >= nums.size() && i != start;
    }
};