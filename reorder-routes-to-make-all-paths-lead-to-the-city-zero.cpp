class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> roads(n);
        vector<bool> visited(n);
        queue<int> curr;
        int ans = 0;

        for(const vector<int> &v : connections){
            roads[v[0]].push_back({v[1], true});
            roads[v[1]].push_back({v[0], false});
        }

        curr.push(0);

        while(!curr.empty()){
            vector<pair<int, bool>> &road = roads[curr.front()];
            visited[curr.front()] = true;
            curr.pop();

            for(const pair<int, bool> &p : road){
                if(!visited[p.first]){
                    curr.push(p.first);
                    if(p.second)
                        ans++;
                } 
            }
        }

        return ans;
    }
};