class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = 1, sizeI = matrix.size(); i < sizeI; i++){
            int prev = i - 1;
            for(int j = 0, sizeJ = matrix[i].size(); j < sizeJ; j++){
                int curr = matrix[i][j], l = j - 1, r = j + 1;

                matrix[i][j] = curr + matrix[prev][j];
                if(r < sizeJ)
                    matrix[i][j] = min(matrix[i][j], curr + matrix[prev][r]);
                if(l >= 0)
                    matrix[i][j] = min(matrix[i][j], curr + matrix[prev][l]);
            }
        }

        return *min_element(matrix[matrix.size()-1].begin(), matrix[matrix.size()-1].end());
    }
};