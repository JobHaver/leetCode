class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, prevX = points[0][0], prevY = points[0][1];
        
        for(vector<int> &v : points){
            int diffX = abs(prevX - v[0]), diffY = abs(prevY - v[1]);
            ans += max(diffX, diffY);
            prevX = v[0];
            prevY = v[1];
        }

        return ans;
    }
};