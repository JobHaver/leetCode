class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<short>, vector<int>> index;
        vector<short> alph(26);
        for(int i = 0; i < strs.size(); i++){
            fill(alph.begin(), alph.end(), 0);
            for(char c : strs[i])
                alph[c - 'a']++;

            index[alph].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto &p : index){
            ans.push_back(vector<string>());
            for(int i : p.second)
                ans.back().push_back(strs[i]);
        }

        return ans;
    }
};