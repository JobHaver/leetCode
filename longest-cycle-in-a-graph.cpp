class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size());
        int ans = -1;
        int cycle = 0;

        for(int i = 0; i < edges.size(); i++){
            cycle++;
            if(!visited[i]){
                int curr = i;
                while(curr > -1 && !visited[curr]){
                    visited[curr] = cycle;
                    curr = edges[curr];
                }

                if(curr > -1 && visited[curr] == cycle){
                    int loop = curr;
                    int count = 1;
                    curr = edges[curr];
                    while(loop != curr){
                        curr = edges[curr];
                        count++;
                    }

                    if(count > ans)
                        ans = count;
                }
            }
        }

        return ans;
    }
};