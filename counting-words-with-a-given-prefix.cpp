class Solution {
private:
    bool isPrefix(string &s1, string &s2){
        if(s1.size() > s2.size())
            return false;

        int i;
        for(i = 0; i < s1.size() && s1[i] == s2[i]; i++);

        return i == s1.size();
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(int i = 0; i < words.size(); i++)
            if(isPrefix(pref, words[i]))
                ans++;

        return ans;
    }
};