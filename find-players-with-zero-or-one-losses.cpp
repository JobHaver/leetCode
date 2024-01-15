class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        vector<vector<int>> ans(2);

        for(vector<int> &v : matches)
            losses[v[0]], losses[v[1]]++;
        
        for(auto &p : losses){
            if(!p.second)
                ans[0].push_back(p.first);
            else if(p.second == 1)
                ans[1].push_back(p.first);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};