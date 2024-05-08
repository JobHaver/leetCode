class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        string places[3] = {"Gold Medal","Silver Medal","Bronze Medal"};
        vector<string> ans(score.size());
        unordered_map<int, int> mp;

        for(int i = 0; i < score.size(); i++)
            mp[score[i]] = i;

        sort(score.begin(), score.end(), greater<int>());

        for(int i = 0; i < score.size() && i < 3; i++)
            ans[mp[score[i]]] = places[i];

        for(int i = 3; i < score.size(); i++)
            ans[mp[score[i]]] = std::to_string(i + 1);

        return ans;
    }
};