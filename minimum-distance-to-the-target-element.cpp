class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = INT_MAX, right = INT_MAX;
        for(int l = start; l >= 0; l--){
            if(nums[l] == target){
                left = abs(l - start);
                break;
            }
        }

        for(int r = start; r < nums.size(); r++){
            if(nums[r] == target){
                right = abs(r - start);
                break;
            }
        }

         return min(left, right);
    }
};