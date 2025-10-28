class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalR = 0, totalL = 0, ans = 0;
        for(int i : nums)
            totalR += i;

        for(int i : nums){
            totalL += i;
            totalR -= i;

            if(i == 0){
                if(totalL == totalR)
                    ans += 2;
                else if(totalL + 1 == totalR || totalR + 1 == totalL)
                    ans += 1;
            }
        }

        return ans;
    }
};