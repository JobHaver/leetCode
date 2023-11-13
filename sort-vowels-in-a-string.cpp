class Solution {
public:
    string sortVowels(string s) {
        vector<int> chars(60); //~ the number needed to get all chars
        string vowels = "AEIOUaeiou";
        for(char c : s)
            chars[c -'A']++;
        
        int i = 0;
        for(char v : vowels){
            for(int curr = v - 'A'; chars[curr]--;){
                for(; vowels.find(s[i]) == string::npos; i++){}
                s[i++] = v;
            }
        }

        return s;
    }
};