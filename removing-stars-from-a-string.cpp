class Solution {
public:
    string removeStars(string s) {
        string word;
        word.reserve(s.size());

        for(const char c : s)
            c == '*' ?  word.pop_back() : word.push_back(c);

        return word;
    }
};