class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        vector<int> ans;
        int maxDiagonal = 0, maxArea = 0, index = 0, cSquared;

        for(int i = 0; i < d.size(); i++){
            cSquared = d[i][1] * d[i][1] + d[i][0] * d[i][0];
            if(cSquared > maxDiagonal){
                maxDiagonal = cSquared;
                ans.clear();
            }

            if(cSquared >= maxDiagonal)
                ans.push_back(i);
        }

        for(int i : ans)
            maxArea = max(maxArea, d[i][0] * d[i][1]);

        return maxArea;
    }
};