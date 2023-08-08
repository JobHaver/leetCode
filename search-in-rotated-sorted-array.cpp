class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        if(nums[l] > nums[r]){
            while(l < r){
                if(nums[m = (l + r + 1) / 2] > nums[l])
                    l = m;
                else
                    r = m - 1;
            }
            l++;
        }

        r = nums.size() - 1 + l; // l is k pivot
        while(l < r){
            if(nums[(m = (l + r + 1) / 2) % nums.size()] <= target)
                l = m;
            else
                r = m - 1;
        }

        return nums[l % nums.size()] == target ? l % nums.size() : -1;
    }
};