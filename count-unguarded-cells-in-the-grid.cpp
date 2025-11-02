class Solution {
public:
    int ans;

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> prison(m, vector<char>(n));
        ans = (m * n) - guards.size() - walls.size();

        for(vector<int> &g : guards)
            prison[g[0]][g[1]] = 'g';
            
        for(vector<int> &w : walls)
            prison[w[0]][w[1]] = 'w';

        for(vector<int> &g : guards){
            for(int up = -1; up + g[0] >= 0; up--)
                if(walk(prison[g[0] + up][g[1]]))
                    break;

            for(int down = 1; down + g[0] < m; down++)
                if(walk(prison[g[0] + down][g[1]]))
                    break;
            
            for(int left = -1; left + g[1] >= 0; left--)
                if(walk(prison[g[0]][g[1] + left]))
                    break;

            for(int right = 1; right + g[1] < n; right++)
                if(walk(prison[g[0]][g[1] + right]))
                    break;
        }

        return ans;
    }

    bool walk(char &curr){
        if(curr == 'g' || curr == 'w')
            return true;

        if(curr != 'v'){
            curr = 'v';
            ans--;
        }

        return false;
    }
};