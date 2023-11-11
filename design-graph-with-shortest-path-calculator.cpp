class Graph {
private:
    vector<vector<pair<int, int>>> edges;

public:
    Graph(int n, vector<vector<int>>& e) {
        edges.resize(n);
        for(vector<int> &v : e)
            edges[v[0]].push_back({v[1], v[2]});
    }
    
    void addEdge(vector<int> v) {
        edges[v[0]].push_back({v[1], v[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int ans = INT_MAX;
        vector<int> costs(edges.size(), -1);
        queue<int> next;

        for(next.push(node1), costs[node1] = 0; !next.empty(); next.pop()){
            int curr = next.front();
            if(costs[curr] >= ans)
                continue;
                
            for(pair<int, int> &p : edges[curr]){
                if(costs[p.first] != -1 && costs[p.first] <= costs[curr] + p.second)
                    continue;

                costs[p.first] = costs[curr] + p.second;
                if(p.first == node2)
                    ans = costs[p.first];
                else
                    next.push(p.first);
            }
        }

        return costs[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */