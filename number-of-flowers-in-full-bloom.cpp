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
        for(int i = 0; i < people.size(); i++){
            auto p = blooming.lower_bound(people[i]);
            ans[i] = p->first == people[i] ? p->second : (--p)->second;
        }

        return ans;
    }
};