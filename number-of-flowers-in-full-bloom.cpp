class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> blooming;

        for(vector<int> &v : flowers)
            blooming[v[0]]++, blooming[v[1] + 1]--;

        int curr = 0;
        blooming[INT_MIN] = curr;
        for(pair<const int, int> &p : blooming)
            p.second = curr += p.second;
            
        vector<int> ans(people.size());
        for(int i = 0; i < people.size(); i++)
            ans[i] = (--blooming.upper_bound(people[i]))->second;

        return ans;
    }
};