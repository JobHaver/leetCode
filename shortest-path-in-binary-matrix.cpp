class Solution {
private:
    struct aStar{
        int key, cost, x, y;

        bool operator<(const aStar &r) const{ // this second const is what was holding me back smh
            return key > r.key;
        }

        aStar(int k, int c, int X, int Y) : key{k}, cost{c}, x{X}, y{Y} {}
    };

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;

        priority_queue<aStar> pq;
        int size = grid.size(), end = (size-1)*2;
        vector<vector<bool>> visited(size, vector<bool>(size));

        visited[0][0] = true;
        pq.push(aStar(0, 1, 0, 0));

        while(!pq.empty()){
            aStar temp = pq.top();
            pq.pop();

            if(temp.x + temp.y == end)
                return temp.cost;

            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    int x = temp.x + i, y = temp.y + j;
                    if(x >= size || y >= size || x < 0 || y < 0 || visited[x][y] || grid[x][y])
                        continue;
                    
                    visited[x][y] = true;
                    pq.push(aStar(temp.cost, temp.cost+1, x, y));
                }
            }
        }
        
        return -1;
    }
};