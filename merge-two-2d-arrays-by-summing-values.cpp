class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;

        for(vector<int> &v : nums1)
            mp[v[0]] += v[1];

        for(vector<int> &v : nums2)
            mp[v[0]] += v[1];

        vector<vector<int>> ans;
        for(auto &p : mp)
            ans.push_back({p.first, p.second});

        return ans;
    }
};