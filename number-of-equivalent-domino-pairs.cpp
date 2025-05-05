class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> mp(10, vector<int>(10));
        int ans = 0;

        for(vector<int> &pair : dominoes){
            int max = std::max(pair[0], pair[1]);
            int min = std::min(pair[0], pair[1]);

            ans += ++mp[min][max] - 1;
        }

        return ans;
    }
};