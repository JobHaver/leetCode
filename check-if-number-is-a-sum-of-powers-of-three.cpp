class Solution {
public:
    bool checkPowersOfThree(int n) {
        int currPowerOfThree = 1;
        for(; n > currPowerOfThree; currPowerOfThree *= 3);

        for(; currPowerOfThree && n; currPowerOfThree /= 3){
            for(;currPowerOfThree > n; currPowerOfThree /= 3);
            n -= currPowerOfThree;
        }

        return !n;
    }
};