class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vx(points.size());
        for(int i = 0; i < points.size(); i++)
            vx[i] = points[i][0];

        sort(vx.begin(), vx.end());

        int prev = vx[0], max = 0;
        for(int i = 0; i < vx.size(); prev = vx[i++])
            max = std::max(max, vx[i] - prev);

        return max;
    }
};