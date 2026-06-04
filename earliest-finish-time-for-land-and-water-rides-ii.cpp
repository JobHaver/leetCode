class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            helper(landStartTime, landDuration, waterStartTime, waterDuration),
            helper(waterStartTime, waterDuration, landStartTime, landDuration));
    }

    int helper(vector<int>& stFirst, vector<int>& durationFirst, vector<int>& stSecond, vector<int>& durationSecond){
        int firstEndTimeMin = INT_MAX;
        for(int i = 0, size = stFirst.size(); i < size; i++)
            firstEndTimeMin = min(stFirst[i] + durationFirst[i], firstEndTimeMin);

        int secondEndTimeMin = INT_MAX;
        for(int i = 0, size = stSecond.size(); i < size; i++)
            secondEndTimeMin = min(max(stSecond[i], firstEndTimeMin) + durationSecond[i], secondEndTimeMin);

        return secondEndTimeMin;
    }
};