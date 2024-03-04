class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, i = 0, j = tokens.size() - 1, ans = 0;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                ans = max(ans, ++score);
            }
            else if(score--)
                power += tokens[j--];
            else
                break;
        }

        return ans;
    }
};