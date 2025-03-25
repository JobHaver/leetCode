class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int day = 0, ans = 0;
        sort(meetings.begin(), meetings.end());
        for(vector<int> &v : meetings){
            if(v[0] > day)
                ans += v[0] - day - 1;
            if(v[1] > day)
                day = v[1];
        }

        return ans + days - day;
    }
};