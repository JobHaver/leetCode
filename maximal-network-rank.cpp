class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> c(n);
        int ans = 0;

        for(vector<int> &r : roads)
            c[r[0]].push_back(r[1]), c[r[1]].push_back(r[0]);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int curr = c[i].size() + c[j].size();
                if(curr > ans)
                    ans = find(c[i].begin(), c[i].end(), j) != c[i].end() ? curr - 1: curr;
            }
        }

        return ans;
    }
};