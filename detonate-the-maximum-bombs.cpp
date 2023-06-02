class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> detonates(bombs.size());

        for(int i = 0; i < bombs.size(); i++){
            for(int j = i+1; j < bombs.size(); j++){
                vector<int> &b1 = bombs[i], &b2 = bombs[j];
                double x = b1[0] - b2[0], y = b1[1] - b2[1], d = sqrt(x*x + y*y);

                if(d <= b1[2])
                    detonates[i].push_back(j);
                
                if(d <= b2[2])
                    detonates[j].push_back(i);
            }
        }

        int maximum = 0;
        queue<int> q;
        for(int i = 0; i < bombs.size(); i++){
            vector<bool> visited(bombs.size());
            int explodes = 1;

            q.push(i);
            visited[q.front()] = true;

            while(!q.empty()){
                for(int curr: detonates[q.front()]){
                    if(!visited[curr]){
                        visited[curr] = true;
                        q.push(curr);
                        explodes++;
                    }
                }

                q.pop();
            }

            maximum = max(explodes, maximum);
        }

        return maximum;
    }
};