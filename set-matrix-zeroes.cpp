class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> xZeros(matrix.size()), yZeros(matrix[0].size());

        for(int x = 0; x < matrix.size(); x++)
            for(int y = 0; y < matrix[0].size(); y++)
                if(!matrix[x][y])
                    xZeros[x] = yZeros[y] = true;

        for(int x = 0; x < matrix.size(); x++)
            for(int y = 0; y < matrix[0].size(); y++)
                if(xZeros[x] || yZeros[y])
                    matrix[x][y] = 0;
    }
};