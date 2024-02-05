class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alph(26, -1);
        for(int i = 0; i < s.size(); i++){
            int &curr = alph[s[i] - 'a'];
            curr = curr == -1 ? i : s.size();
        }

        int ans = s.size();
        for(int i : alph)
            if(i != -1 && i != s.size())
                ans = min(ans, i);

        return ans == s.size() ? -1 : ans;
    }
};