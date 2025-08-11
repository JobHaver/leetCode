class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
            ans[i].resize(i+1);
            ans[i].front() = 1;
            ans[i].back() = 1;

            if(i == 0)
                continue;

            for(int j = 1, p = i-1; j < ans[p].size(); j++)
                ans[i][j] = ans[p][j] + ans[p][j-1];
        }

        return ans;
    }
};