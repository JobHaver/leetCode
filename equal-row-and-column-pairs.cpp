class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> seen;
        int ans = 0;
        int n = grid.size();
        vector<int> temp(n);

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++)
                temp[y] = grid[x][y];
            
            seen[temp]++;
        }

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++)
                temp[y] = grid[y][x];
            
            ans += seen[temp];
        }

        return ans;
    }
};