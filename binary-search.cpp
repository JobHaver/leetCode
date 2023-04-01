class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), middle;

        while(left < right){
            middle = (left + right) / 2;

            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target)
                left = middle + 1;
            else
                right = middle;
        }

        return -1;
    }
};