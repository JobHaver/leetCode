class Solution {
public:
    int integerBreak(int n) {
        if(n < 3)
            return 1;
        else if(n == 3)
            return 2;

        int ans = 1;
        for(; n > 4; n -= 3)
            ans *= 3;

        return ans * n;
    }
};