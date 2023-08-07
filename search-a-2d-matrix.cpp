class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, m, i;
        while(l < r){
            if(matrix[m = (l + r + 1) / 2][0] <= target)
                l = m;
            else
                r = m - 1;
        }

        i = l, l = 0, r = matrix[i].size() - 1;
        while(l < r){
            if(matrix[i][m = (l + r + 1) / 2] <= target)
                l = m;
            else
                r = m - 1;
        }
        
        return matrix[i][l] == target;
    }
};