class Solution {
private:
    int alphSize = 26;

public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;

        vector<int> alph1(alphSize);
        vector<int> alph2(alphSize);
        for(char c : word1)
            alph1[c - 'a']++;
        for(char c : word2)
            alph2[c - 'a']++;

        for(int i = 0; i < alphSize; i++){
            if(!alph1[i] && !alph2[i])
                continue;
            if(!alph1[i] || !alph2[i])
                return false;
        }

        sort(alph1.begin(), alph1.end());
        sort(alph2.begin(), alph2.end());
        
        return alph1 == alph2;
    }
};