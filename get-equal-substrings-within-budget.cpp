class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size());
        for(int i = 0; i < s.size(); i++)
            diff[i] = abs(s[i] - t[i]);

        int ans = 0;
        for(int l = 0, r = 0, curr = 0; r < s.size(); r++){
            if((maxCost -= diff[r]) < 0)
                for(curr--; (maxCost += diff[l++]) < 0; curr--);

            ans = max(++curr, ans);
        }
            
        return ans;
    }
};