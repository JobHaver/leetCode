class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, ts;

        for(char c : s)
            if(c != '#') ss.push_back(c); else if(!ss.empty()) ss.pop_back();
            
        for(char c : t)
            if(c != '#') ts.push_back(c); else if(!ts.empty()) ts.pop_back();
        
        return ss == ts;
    }
};