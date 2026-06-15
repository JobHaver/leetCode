class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string &s : words){
            int total = 0;
            for(char c : s)
                total += weights[c - 'a'];

            ans += 'z' - (total % 26);
        }

        return ans;
    }
};