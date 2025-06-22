class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size();){
            string curr;
            for(int j = 0; j < k; j++)
                curr += i < s.size() ? s[i++] : fill;

            ans.push_back(curr);
        }

        return ans;
    }
};