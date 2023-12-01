class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, s1 = 0, s2 = 0;
        while(s1 < word1.size() && s2 < word2.size()){
            if(word1[s1][i] != word2[s2][j])
                return false;

            if(word1[s1].size() == ++i)
                s1++, i = 0;
            if(word2[s2].size() == ++j)
                s2++, j = 0;
        }

        return s1 == word1.size() && s2 == word2.size();
    }
};