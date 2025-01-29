class Solution {
private:
    int fishHelper(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] == 0)
            return 0;

        int temp = grid[x][y];
        grid[x][y] = 0;

        return temp +
        fishHelper(grid, x + 1, y) +
        fishHelper(grid, x - 1, y) +
        fishHelper(grid, x, y + 1) +
        fishHelper(grid, x, y - 1);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] != 0)
                    max = std::max(max, fishHelper(grid, i, j));

        return max;
    }
};