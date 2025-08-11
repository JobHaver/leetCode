class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size());
        int ans = 0, i;

        for(int fruit : fruits){
            for(i = 0; i < baskets.size(); i++){
                if(used[i] || fruit > baskets[i])
                    continue;

                used[i] = true;
                break;
            }

            if(i >= baskets.size())
                ans++;
        }

        return ans;
    }
};