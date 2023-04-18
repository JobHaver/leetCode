class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int sizeMin = min(word1.size(), word2.size());
        string ans;
        ans.resize(word1.size() + word2.size());
        int i = 0;
        int j = 0;

        while(i < sizeMin){
            ans[j++] = word1[i];
            ans[j++] = word2[i++];
        }

        while(i < word1.size())
            ans[j++] = word1[i++];
        
        while(i < word2.size())
            ans[j++] = word2[i++];

        return ans;
    }
};