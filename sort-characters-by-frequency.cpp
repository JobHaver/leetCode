class Solution {
public:
    string frequencySort(string s) {
        vector<int> alph(75); //roughly unicode distance between 0 and z
        vector<pair<int, int>> sort;

        for(char c : s)
            alph[c - '0']++;

        for(int i = 0; i < alph.size(); i++)
            if(alph[i]) sort.push_back({alph[i], i});

        std::sort(sort.begin(), sort.end());

        string ans;
        for(pair<int, int> &p : sort)
            ans = string(p.first, p.second + '0') + ans;

        return ans;
    }
};