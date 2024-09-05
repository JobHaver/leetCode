class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalRolls = rolls.size() + n;
        int numberNeeded = totalRolls * mean;
        int currentNumber = 0;

        for(int i : rolls)
            currentNumber += i;

        vector<int> ans(n), emptyAns;

        for(int i = 0, numRemaining = numberNeeded - currentNumber; n; n--, i++){
            numRemaining -= ans[i] = numRemaining / n;
            if(ans[i] > 6 || ans[i] < 1)
                return emptyAns;
        }
        
        return ans;
    }
};