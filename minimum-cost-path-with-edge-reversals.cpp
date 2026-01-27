class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> map(n);
        vector<int> costs(n, INT_MAX);

        for(vector<int> &v : edges){
            map[v[0]].push_back({v[1], v[2]});
            map[v[1]].push_back({v[0], v[2] * 2});
        }

        queue<int> currPoints;
        currPoints.push(0);
        costs[0] = 0;
        while(currPoints.size() != 0){
            for(int currSize = currPoints.size(), i = 0; i < currSize; i++){
                int curr = currPoints.front();

                for(pair<int, int> &p : map[curr]){
                    if(costs[curr] + p.second < costs[p.first]){
                        currPoints.push(p.first);
                        costs[p.first] = costs[curr] + p.second;
                    }
                }

                currPoints.pop();
            }
        }

        return costs[n-1] == INT_MAX ? -1 : costs[n-1];
    }
};