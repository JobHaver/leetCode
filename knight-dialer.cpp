class Solution {
public:
    int knightDialer(int n) {
        vector<vector<short>> legalMoves {{4,6}, {8,6}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
        vector<unsigned int> curr(legalMoves.size()), prev(legalMoves.size(), 1);

        int ans = 0, mod = 1000000007;
        while(--n){
            for(int i = 0; i < legalMoves.size(); i++){
                for(short num : legalMoves[i])
                    curr[num] += prev[i];
            }

            for(int i = 0; i < legalMoves.size(); curr[i++] = 0)
                prev[i] = curr[i] % mod;
        }

        for(unsigned int i : prev)
            ans += i, ans %= mod;

        return ans;
    }
};