class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        mat[0] = matrix[0];
        for(int i = 0, sizeI = matrix.size() - 1; i < sizeI; i++){
            int next = i + 1;
            for(int j = 0, sizeJ = matrix[i].size(); j < sizeJ; j++){
                int curr = mat[i][j], l = j - 1, r = j + 1;

                if(r < sizeJ)
                    mat[next][r] = min(mat[next][r], curr + matrix[next][r]);
                if(l >= 0)
                    mat[next][l] = min(mat[next][l], curr + matrix[next][l]);
                mat[next][j] = min(mat[next][j], curr + matrix[next][j]);
            }
        }

        return *min_element(mat[mat.size()-1].begin(), mat[mat.size()-1].end());
    }
};