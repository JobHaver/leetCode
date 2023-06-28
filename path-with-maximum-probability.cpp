class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n);
        vector<vector<pair<int, double>>> paths(n);
        queue<int> curr;

        for(int i = 0; i < edges.size(); i++){
            vector<int> &temp = edges[i];
            paths[temp[0]].push_back({temp[1], succProb[i]});
            paths[temp[1]].push_back({temp[0], succProb[i]});
        }

        curr.push(start);
        prob[start] = 1;

        while(!curr.empty()){
            for(pair<int, double>& i : paths[curr.front()]){
                double p = i.second * prob[curr.front()];
                if(p > prob[i.first]){
                    prob[i.first] = p;
                    curr.push(i.first);
                }
            }

            curr.pop();
        }

        return prob[end];
    }
};