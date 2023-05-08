class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat[0].size() - 1;
        
        for(int i = 0; i < mat.size(); i++)
            ans += mat[i][i] + mat[i][n-i];

        return mat.size() % 2 == 0 ? ans : ans - mat[mat.size()/2][mat.size()/2];
    }
};