class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> letters(26);
        int numOfTypedWords = 0;

        for(char c : brokenLetters)
            letters[c-'a'] = true;

        bool typeableWord = true;
        for(char c : text){
            if(c == ' '){
                if(typeableWord == true)
                    numOfTypedWords++;
                typeableWord = true;
            }
            else if(letters[c-'a'])
                typeableWord = false;
        }

        return typeableWord ? numOfTypedWords + 1 : numOfTypedWords;
    }
};