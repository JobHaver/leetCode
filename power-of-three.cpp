class Solution {
public:
    bool isPowerOfThree(int n) {
        for(long long curr = 1; curr <= n; curr *= 3)
            if(curr == n)
                return true;

        return false;
    }
};