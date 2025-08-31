class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        sortMatrixRight(0, 1, grid);
        sortMatrixDown(0, 0, grid);

        return grid;
    }

    void sortMatrixDown(int x, int y, vector<vector<int>>& grid){
        if(x >= grid.size())
            return;

        sortDiagonal(x, y, grid, false);
        sortMatrixDown(++x, y, grid);
    }

    void sortMatrixRight(int x, int y, vector<vector<int>>& grid){
        if(y >= grid[x].size())
            return;

        sortDiagonal(x, y, grid, true);
        sortMatrixRight(x, ++y, grid);
    }

    void sortDiagonal(int x, int y, vector<vector<int>>& grid, bool asc){
        vector<int> toSort;

        for(int i = x, j = y; i < grid.size() && j < grid[i].size(); i++, j++)
            toSort.push_back(grid[i][j]);

        if(asc)
            sort(toSort.begin(), toSort.end());
        else
            sort(toSort.begin(), toSort.end(), greater<int>());

        for(int i = x, j = y, curr = 0; i < grid.size() && j < grid[i].size(); i++, j++, curr++)
            grid[i][j] = toSort[curr];
    }
};