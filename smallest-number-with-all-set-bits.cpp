class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0, currPow2 = 1;

        while(ans < n){
            ans += currPow2;
            currPow2 *= 2;
        }

        return ans;
    }
};