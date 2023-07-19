class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());

        for(int i = 0, j = 1; j < intervals.size(); i++, j++){
            if(intervals[i][1] > intervals[j][0]){
                intervals[j][1] = min(intervals[i][1], intervals[j][1]);
                ans++;
            }
        }

        return ans;
    }
};