class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        int ans = 0;
        for(int i = 0; n; i++){
            if(n & (1 << i))
                n ^= 1 << i;
            else
                ans |= 1 << i;
        }

        return ans;
    }
};