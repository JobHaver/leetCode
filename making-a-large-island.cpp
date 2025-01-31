class Solution {
private:
    int currCount = 0;
    int curr = 2;
    vector<int> islandsSize;

    void islandFinder(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1)
            return;

        grid[i][j] = curr;
        currCount++;

        islandFinder(grid, i + 1, j);
        islandFinder(grid, i - 1, j);
        islandFinder(grid, i, j + 1);
        islandFinder(grid, i, j - 1);
    }

    int islandCombiner(vector<vector<int>>& grid, int i, int j){
        vector<int> islands;
        int max = 0;

        if(i + 1 < grid.size() && grid[i + 1][j] > 1)
            islands.push_back(grid[i + 1][j]);
        if(i - 1 >= 0 && grid[i - 1][j] > 1 && islands.end() == find(islands.begin(), islands.end(), grid[i - 1][j]))
            islands.push_back(grid[i - 1][j]);
        if(j + 1 < grid[i].size() && grid[i][j + 1] > 1 && islands.end() == find(islands.begin(), islands.end(), grid[i][j + 1]))
            islands.push_back(grid[i][j + 1]);
        if(j - 1 >= 0 && grid[i][j - 1] > 1 && islands.end() == find(islands.begin(), islands.end(), grid[i][j - 1]))
            islands.push_back(grid[i][j - 1]);
            
        for(int &i : islands)
            max += islandsSize[i-2];

        return max + 1;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    islandFinder(grid, i, j);
                    islandsSize.push_back(currCount);
                    currCount = 0;
                    curr++;
                }
            }
        }

        if(islandsSize.size() == 0)
            return 1;

        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 0)
                    ans = max(ans, islandCombiner(grid, i, j));

        return ans ? ans : grid.size() * grid[0].size();
    }
};