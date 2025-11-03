class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, max, total;

        for(int i = 0; i < colors.size();){
            max = 0, total = 0;
            for(char curr = colors[i]; i < colors.size() && colors[i] == curr; i++){
                max = std::max(max, neededTime[i]);
                total += neededTime[i];
            }

            ans += total - max;
        }

        return ans;
    }
};