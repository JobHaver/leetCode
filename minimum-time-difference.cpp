class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> converted(tp.size());
        for(int i = 0; i < tp.size(); i++)
            converted[i] = (((tp[i][0] - '0') * 10) + (tp[i][1] - '0')) * 60 + (((tp[i][3] - '0') * 10) + (tp[i][4] - '0'));
        
        sort(converted.begin(), converted.end());

        int min = INT_MAX;
        for(int i = 1; i < converted.size(); i++)
            if((converted[i] - converted[i-1]) < min)
                min = converted[i] - converted[i-1];

        return std::min((converted[0] + 1440) - converted[tp.size()-1],  min);
    }
};