public class Solution {
    public int BagOfTokensScore(int[] tokens, int power) {
        Array.Sort(tokens);
        int score = 0, i = 0, j = tokens.Length - 1, ans = 0;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                ans = Math.Max(ans, ++score);
            }
            else if(score-- != 0)
                power += tokens[j--];
            else
                break;
        }

        return ans;
    }
}