class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> dest(n);
        vector<int> visited(n, INT_MAX);

        visited[src] = 0;
        for(vector<int> &v : flights)
            dest[v[0]].push_back({v[1], v[2]});

        queue<pair<int, int>> curr;
        curr.push({src, 0});
        for(int i = -1; i < k; i++)
            for(int j = curr.size(); j--; curr.pop())
                for(pair<int, int> &p : dest[curr.front().first])
                    if(visited[p.first] > curr.front().second + p.second)
                        visited[p.first] = curr.front().second + p.second, curr.push({p.first, visited[p.first]});

        return visited[dst] == INT_MAX ? -1 : visited[dst];
    }
};