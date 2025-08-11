class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size());
        int ans = 0, i;

        for(int fruit : fruits){
            for(i = 0; i < baskets.size() && (used[i] || fruit > baskets[i]); i++);

            if(i >= baskets.size())
                ans++;
            else
                used[i] = true;
        }

        return ans;
    }
};