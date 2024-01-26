class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> grid1(m, vector<int>(n)), grid2(m, vector<int>(n));
        bool swap = false;
        long ans = 0;
        int mod = 1e9 + 7;

        for(grid1[startRow][startColumn]++; maxMove--; swap = !swap){
            vector<vector<int>> &g1 = !swap ? grid1 : grid2;
            vector<vector<int>> &g2 = !swap ? grid2 : grid1;

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    long tot = 0;
                    if(i+1 < m) tot += g1[i+1][j]; else ans += g1[i][j];
                    if(i-1 >= 0) tot += g1[i-1][j]; else ans += g1[i][j];
                    if(j+1 < n) tot += g1[i][j+1]; else ans += g1[i][j];
                    if(j-1 >= 0) tot += g1[i][j-1]; else ans += g1[i][j];
                    g2[i][j] = tot % mod;
                    ans %= mod;
                }
            }
        }

        return ans;
    }
};