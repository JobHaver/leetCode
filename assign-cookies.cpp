class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        for(int i = 0, j = 0; i < g.size(); i++, j++, ans++){
            for(; j < s.size() && g[i] > s[j]; j++);
            if(j >= s.size())
                break;
        };

        return ans;
    }
};