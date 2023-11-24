class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;

        for(int i = 0, r = piles.size(); i < piles.size(); i += 3)
            ans += piles[r -= 2];

        return ans;
    }
};