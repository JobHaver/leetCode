class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string newString;
            for(int i = 1; i < s.size(); i++)
                newString += ((s[i]-'0') + (s[i-1]-'0')) % 10;
            
            s = newString;
        }

        return s[0] == s[1];
    }
};