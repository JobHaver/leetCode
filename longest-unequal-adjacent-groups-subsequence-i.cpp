class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;

        for(int i = 0, prev = 2; i < words.size(); i++){
            if(prev != groups[i])
                ans.push_back(words[i]);

            prev = groups[i];
        }

        return ans;
    }
};