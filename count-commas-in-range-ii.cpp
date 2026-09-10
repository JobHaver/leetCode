class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, currSubtraction = 999;
        for(n -= currSubtraction; n > 0; n -= (currSubtraction *= 1000))
            ans += n;

        return ans;
    }
};