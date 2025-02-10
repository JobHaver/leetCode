class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for(char c : s){
            if(c-'9' <= 0 && !ans.empty())
                ans.pop_back();
            else
                ans += c;
        }

        return ans;
    }
};