typedef tuple<int,int,int> tup;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size(), time, currX, currY;
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<tup, vector<tup>, greater<tup>> pq;

        pq.push({0, 0, 0});
        visited[0][0] = true;

        vector<pair<int, int>> locations({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        while(!pq.empty()){
            auto [currTime, currX, currY] = pq.top();
            pq.pop();
            
            if(currX == n-1 && currY == m-1)
                return currTime;
            
            for(pair<int, int> &p : locations){
                int x = p.first + currX, y = p.second + currY;
                if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]){
                    visited[x][y] = true;
                    pq.push({max(currTime, moveTime[x][y]) + 1, x, y});
                } 
            }
        }
        
        return -1;
    }
};