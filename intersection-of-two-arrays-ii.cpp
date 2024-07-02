class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> mp;

        for(int i : nums1)
            mp[i].first++;
        
        for(int i : nums2)
            mp[i].second++;
        
        vector<int> ans;
        for(pair<const int, pair<int,int>> &p : mp)
            while(p.second.first-- && p.second.second--)
                ans.push_back(p.first);

        return ans;
    }
};