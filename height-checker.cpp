class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights);
        int ans = 0;

        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < heights.size(); i++)
            if(sorted[i] != heights[i])
                ans++;

        return ans;
    }
};