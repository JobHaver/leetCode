class Solution {
private:
    #define pp pair<int, int>
    pp directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0, sizeX = heights.size(), sizeY = heights[0].size();
        vector<vector<int>> costs(sizeX, vector<int>(sizeY, INT_MAX));
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        pq.push({0, 0});
        while(!pq.empty()){
            int n = pq.top().second / sizeY, m = pq.top().second % sizeY;
            ans = max(ans, pq.top().first);
            pq.pop();

            if(n == sizeX-1 && m == sizeY-1)
                return ans;

            int cost;
            for(pp &p : directions){
                int x = n + p.first, y = m + p.second;
                if(x >= 0 && x < sizeX && y >= 0 && y < sizeY && costs[x][y] > (cost = abs(heights[n][m] - heights[x][y]))){
                    costs[x][y] = cost;
                    pq.push({cost, (x * sizeY) + y});
                }
            }
        }

        return -1;
    }
};