class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total(cost.size() + 2, INT_MAX);
        total[0] = 0, total[1] = 0;

        for(int i = 0; i < cost.size(); i++){
            int c = total[i] + cost[i];
            if(c < total[i+1])
                total[i+1] = c;
            if(c < total[i+2])
                total[i+2] = c;
        }

        return total[cost.size()];
    }
};