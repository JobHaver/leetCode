class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> words;
        stringstream string1(s1);
        stringstream string2(s2);
        string temp;

        while (getline(string1, temp, ' '))
            words[temp]++;
        
        while (getline(string2, temp, ' '))
            words[temp]++;
        
        for(auto &p : words)
            if(p.second == 1)
                ans.push_back(p.first);

        return ans;
    }
};