class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        for(int currGap = INT_MIN; n; n >>= 1){
            if(n & 1){
                ans = max(ans, currGap);
                currGap = 1;
            }
            else
                currGap++;
        }

        return ans;
    }
};