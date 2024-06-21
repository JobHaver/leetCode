class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int nonGrumpScore = 0, grumpScore = 0, grumpScoreMax = 0;
        for(int i = 0; i < minutes && i < customers.size(); i++){
            if(grumpy[i])
                grumpScoreMax += customers[i];
            else
                nonGrumpScore += customers[i];
        }

        grumpScore = grumpScoreMax;
        for(int l = 0, r = minutes; r < customers.size(); l++, r++){
            if(grumpy[l])
                grumpScore -= customers[l];

            if(grumpy[r])
                grumpScore += customers[r];
            else
                nonGrumpScore += customers[r];

            grumpScoreMax = max(grumpScoreMax, grumpScore);
        }

        return grumpScoreMax + nonGrumpScore;
    }
};