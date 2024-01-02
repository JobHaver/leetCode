class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> n;

        int max = 0;
        for(int i : nums)
            max = std::max(max, ++n[i]);

        vector<vector<int>> ans(max);
        for(auto &p : n){
            while(p.second--)
                ans[p.second].push_back(p.first);
        }

        return ans;
    }
};