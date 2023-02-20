class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 1;
        int pos = 0;

        if(nums.size()<=1)
            return 0;

        while(pos+nums[pos] < nums.size()-1){
            int bestPos=-1, bestDis=-1;

            for(int i=1; i < nums[pos]+1; i++){
                if(nums[pos+i]+i > bestDis && nums[pos+i] != 0){
                    bestPos = pos+i;
                    bestDis = nums[pos+i]+i;
                }
            }
            
            pos = bestPos;
            ans++;
        }

        return ans;
    }
};