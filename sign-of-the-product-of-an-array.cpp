class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ans = true;
        for(int& i : nums){
            if(i < 0)
                ans = !ans;
            else if(!i)
                return 0;
        }
        
        return ans ? 1 : -1;
    }
};