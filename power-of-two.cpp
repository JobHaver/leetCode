class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(fmod(log2(n), 1.0));
    }
};