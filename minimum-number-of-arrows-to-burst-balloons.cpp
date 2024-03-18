class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, curr = points[0][1];
        for(vector<int> &p : points){
            if(p[0] > curr){
                ans++;
                curr = p[1];
            }
            else
                curr = min(curr, p[1]);
        }

        return ans;
    }
};