class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0, size = mat[i].size(); j < size; j += 2)
                if(mat[i][(j + k) % size] != mat[i][j])
                    return false;
        
        for(int i = 0; i < mat.size(); i++)
            for(int j = 1, size = mat[i].size(), kNew = k % size; j < size; j += 2)
                if(mat[i][(j - kNew + size) % size] != mat[i][j])
                    return false;

        return true;
    }
};