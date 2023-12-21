class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vx(points.size());
        for(int i = 0; i < points.size(); i++)
            vx[i] = points[i][0];

        sort(vx.begin(), vx.end());

        int max = 0;
        for(int i = 1; i < vx.size(); i++)
            max = std::max(max, vx[i] - vx[i-1]);

        return max;
    }
};