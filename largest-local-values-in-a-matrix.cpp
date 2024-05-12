class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid[0].size() - 2));

        for(int i = 1, sizeI = grid.size() - 1; i < sizeI; i++){
            for(int j = 1, sizeJ = grid[i].size() - 1; j < sizeJ; j++){
                int max = grid[i][j];
                for(int im = -1; im < 2; im++)
                    for(int jm = -1; jm < 2; jm++)
                        max = std::max(max, grid[i+im][j+jm]);

                ans[i - 1][j - 1] = max;
            }
        }

        return ans;
    }
};