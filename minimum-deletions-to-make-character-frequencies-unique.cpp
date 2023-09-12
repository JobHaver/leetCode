class Solution {
public:
    int minDeletions(string s) {
        vector<int> alp(26);

        for(char c : s)
            alp[c-'a']++;
        
        sort(alp.begin(), alp.end(), greater<int>());

        int ans = 0;
        for(int i = 1, prev = alp[0]; i < alp.size(); prev = alp[i++]){
            if(prev <= alp[i]){
                int dif = prev != 0 ? (alp[i] - prev) + 1 : (alp[i] - prev);
                ans += dif;
                alp[i] -= dif;
            }
        }

        return ans;
    }
};