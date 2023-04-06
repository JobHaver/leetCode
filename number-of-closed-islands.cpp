class Solution {
private:
    int land;

    void islandFinder(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 1;

        if(x+1 >= grid.size()) land++; 
        else if(!grid[x+1][y]) islandFinder(grid, x+1, y);

        if(x-1 < 0) land++; 
        else if(!grid[x-1][y]) islandFinder(grid, x-1, y);

        if(y+1 >= grid[x].size()) land++; 
        else if(!grid[x][y+1]) islandFinder(grid, x, y+1);

        if(y-1 < 0) land++; 
        else if(!grid[x][y-1]) islandFinder(grid, x, y-1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(!grid[i][j]){
                    land = 0;
                    islandFinder(grid, i , j);

                    if(!land)
                        ans++;
                }
            }
        }

        return ans;
    }
};