class Solution {
public:
    string makeFancyString(string s) {
        stringstream ss;
        int charCount = 1;
        char prevChar = '!';
        for(char c : s){
            charCount = c == prevChar ? charCount + 1 : 1;
            if(charCount < 3)
                ss.put(c);

            prevChar = c;
        }

        return ss.str();
    }
};