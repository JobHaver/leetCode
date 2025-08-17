class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;

        for(long long curr = 1; curr <= n; curr *= 4)
            if(curr == n)
                return true;

        return false;
    }
};