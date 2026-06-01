class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(), cost.end());

        for(int i = cost.size()-1, skip = 0; i >= 0; i--){
            if(++skip == 3)
                skip = 0;
            else
                ans += cost[i];
        }

        return ans;
    }
};