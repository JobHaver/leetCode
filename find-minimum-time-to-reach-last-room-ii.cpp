typedef tuple<int,int,int,int> tup;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size(), time, currX, currY;
        bool one;
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<tup, vector<tup>, greater<tup>> pq;

        pq.push({0, 0, 0, true});
        visited[0][0] = true;

        vector<pair<int, int>> locations({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        while(!pq.empty()){
            auto [currTime, currX, currY, one] = pq.top();
            pq.pop();
            
            for(pair<int, int> &p : locations){
                int x = p.first + currX, y = p.second + currY;

                if(x == n-1 && y == m-1)
                    return max(currTime, moveTime[x][y]) + (one ? 1 : 2);
                
                if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]){
                    visited[x][y] = true;
                    pq.push({max(currTime, moveTime[x][y]) + (one ? 1 : 2), x, y, !one});
                } 
            }
        }
        
        return -1;
    }
};