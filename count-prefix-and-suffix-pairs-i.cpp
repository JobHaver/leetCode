class Solution {
private:
    bool isPrefix(string &s1, string &s2){
        if(s1.size() > s2.size())
            return false;

        int i;
        for(i = 0; i < s1.size() && s1[i] == s2[i]; i++);

        return i == s1.size();
    }

    bool isSuffix(string &s1, string &s2){
        if(s1.size() > s2.size())
            return false;

        int i = s1.size()-1;
        for(int j = s2.size()-1; i > -1 && s1[i] == s2[j]; i--, j--);

        return i < 0;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;

        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if(isSuffix(words[i], words[j]) && isPrefix(words[i], words[j]))
                    ans++;

        return ans;
    }
};