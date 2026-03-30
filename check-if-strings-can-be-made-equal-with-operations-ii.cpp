class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;

        vector<int> even(26), odd(26);
        for(int i = 0; i < s1.size(); i += 2)
            even[s1[i] - 'a']++, even[s2[i] - 'a']--;

        for(int i = 1; i < s1.size(); i += 2)
            odd[s1[i] - 'a']++, odd[s2[i] - 'a']--;

        for(int i = 0; i < 26; i++)
            if(even[i] != 0 || odd[i] != 0)
                return false;

        return true;
    }
};