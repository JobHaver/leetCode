class Solution {
private:
    vector<vector<bool>> moves;
    vector<vector<int>> *g;
    int max = 0;

    int helper(int i, int j, int curr){
        if(j >= (*g)[0].size() || moves[i][j] || curr >= (*g)[i][j])
            return 0;

        moves[i][j] = true;
        curr = (*g)[i][j++];

        int maxMoves = helper(i, j, curr);
        if(i+1 < (*g).size())
            maxMoves = std::max(maxMoves, helper(i+1, j, curr));
        if(i-1 >= 0)
            maxMoves = std::max(maxMoves, helper(i-1, j, curr));

        return maxMoves + 1;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        moves.resize(grid.size(), vector<bool>(grid[0].size()));
        g = &grid;

        for(int i = 0; i < grid.size(); i++)
            max = std::max(max, helper(i, 0, -1));

        return max - 1;
    }
};