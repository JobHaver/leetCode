class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sizeY = grid.size();
        int neg = 0, j = grid[0].size() - 1;

        for(int i = 0; i < sizeY; i++){
            for(; j >= 0 && grid[i][j] < 0; j--)
                neg += sizeY - i;
        }

        return neg;
    }
};