class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> toSort(heights.size());

        for(int i = 0; i < heights.size(); i++)
            toSort[i] = {heights[i], i};

        sort(toSort.begin(), toSort.end());

        vector<string> ans(heights.size());
        for(int i = 0; i < heights.size(); i++)
            ans[i] = names[toSort[heights.size() - i - 1].second];

        return ans;
    }
};