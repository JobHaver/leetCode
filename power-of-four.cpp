class Solution {
public:
    bool isPowerOfFour(int n) {
        for(long curr = 1; curr <= n; curr *= 4)
            if(curr == n) return true;

        return false;
    }
};