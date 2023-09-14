class Solution {
private:
    #define pq priority_queue<string, vector<string>, greater<string>>
    unordered_map<string, pq> mp;
    vector<string> ans;
    
    void dfs(string airport){
        pq &curr = mp[airport];
        while(!curr.empty()){
            string temp = curr.top();
            curr.pop();
            dfs(temp);
        }

        ans.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear(), ans.clear();
        for(vector<string> &v : tickets)
            mp[v[0]].push(v[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};