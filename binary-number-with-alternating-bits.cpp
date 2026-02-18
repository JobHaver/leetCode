class Solution {
public:
    bool hasAlternatingBits(int n) {
        for(bool curr = !(n&0x01); n ; curr = !curr, n >>= 1)
            if(curr == (n&0x01))
                return false;

        return true;
    }
};