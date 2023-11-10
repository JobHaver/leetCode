class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans(adjacentPairs.size() + 1);

        for(vector<int> &v : adjacentPairs)
            mp[v[0]].push_back(v[1]), mp[v[1]].push_back(v[0]);

        int curr;
        for(pair<const int, vector<int>> &p : mp){ //find a starting point
            if(p.second.size() == 1){
                curr = p.first;
                break;
            }
        }
        
        int prev = INT_MIN, next, size = ans.size() - 1;
        for(int i = 0; i < size; i++){
            ans[i] = curr;
            vector<int> &v = mp[curr];
            next = v[0] != prev ? v[0] : v[1];
            prev = curr;
            curr = next;
        }
        ans[size] = curr; //done because last element only has 1 element

        return ans;
    }
};