class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < routes.size(); i++){
            for(int j : routes[i])
                mp[j].push_back(i);
        }

        int ans = 1;
        queue<int> buses;
        vector<bool> visited(routes.size());
        for(int b : mp[source]){
            buses.push(b);
            visited[b] = true;
        }
        
        for(int size = buses.size(); size; ans++, size = buses.size()){
            for(; size--; buses.pop()){
                for(int r : routes[buses.front()]){
                    if(r == target)
                        return ans;
                    
                    vector<int> &stops = mp[r];
                    for(int b : stops){
                        if(visited[b])
                            continue;
                        visited[b] = true;
                        buses.push(b);
                    }

                    stops.clear(); //done so don't revisit
                }
            }
        }

        return -1;
    }
};