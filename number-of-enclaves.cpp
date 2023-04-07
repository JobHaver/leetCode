class Solution {
private:
    int land;
    bool valid;

    void islandFinder(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        land++;

        if(x+1 >= grid.size()) valid = false;
        else if(grid[x+1][y]) islandFinder(grid, x+1, y);

        if(x-1 < 0) valid = false; 
        else if(grid[x-1][y]) islandFinder(grid, x-1, y);

        if(y+1 >= grid[x].size()) valid = false; 
        else if(grid[x][y+1]) islandFinder(grid, x, y+1);

        if(y-1 < 0) valid = false; 
        else if(grid[x][y-1]) islandFinder(grid, x, y-1);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    land = 0;
                    valid = true;
                    islandFinder(grid, i , j);

                    if(valid)
                        ans += land;
                }
            }
        }

        return ans;
    }
};