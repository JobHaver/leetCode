class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotatedOnce = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                if(rotatedOnce)
                    return false;
                else
                    rotatedOnce = true;
            }
        }

        return rotatedOnce ? nums[0] >= nums[nums.size()-1] : true;
    }
};