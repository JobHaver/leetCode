class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> citys;
        for(vector<string> &s : paths)
            citys[s[0]] = true, citys[s[1]];

        for(pair<const string, bool> &p: citys)
            if(!p.second) return p.first;

        return "";
    }
};