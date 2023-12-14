class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int sizeI = grid.size(), sizeJ = grid[0].size();
        vector<int> countI(sizeI), countJ(sizeJ);
        
        for(int i = 0; i < sizeI; i++){
            for(int j = 0; j < sizeJ; j++)
                if(grid[i][j]) countI[i]++, countJ[j]++;
        }

        for(int i = 0; i < sizeI; i++){
            for(int j = 0; j < sizeJ; j++)
                grid[i][j] = countI[i] + countJ[j] - (sizeI - countI[i]) - (sizeJ - countJ[j]);
        }

        return grid;
    }
};