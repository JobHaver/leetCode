class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i = 1, size = rating.size()-1; i < size; i++){
            int greaterL = 0, greaterR = 0;
            for(int l = i - 1; l >= 0; l--)
                if(rating[l] > rating[i])
                    greaterL++;

            for(int r = i + 1; r < rating.size(); r++)
                if(rating[r] > rating[i])
                    greaterR++;

            ans += (i - greaterL) * greaterR + greaterL * (size - i - greaterR);
        }

        return ans;
    }
};