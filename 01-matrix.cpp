class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> expand;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(!mat[i][j])
                    ans[i][j] = 0, expand.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int val = 1; !expand.empty(); val++){
            for(int i = 0, size = expand.size(); i < size; expand.pop(), i++){
                for(pair<int, int> p : directions){
                    int x = expand.front().first + p.first, y = expand.front().second + p.second;
                    if(x >= 0 && x < mat.size() && y >= 0 && y < mat[x].size() && ans[x][y] > val){
                        ans[x][y] = val;
                        expand.push({x, y});
                    }
                }
            }
        }

        return ans;
    }
};