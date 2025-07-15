class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;

        bool vowel = false, consonant = false;

        for(char c : word){
            if(c > 47 && c < 58)
                continue;
            else if((c > 64 && c < 91) || (c > 96 && c < 123)){
                if(c == 'a' || c == 'A' || 
                   c == 'e' || c == 'E' || 
                   c == 'i' || c == 'I' || 
                   c == 'o' || c == 'O' || 
                   c == 'u' || c == 'U')
                    vowel = true;
                else
                    consonant = true;
            }
            else
                return false;
        }

        return vowel && consonant;
    }
};