class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        for(int i = 0, j, wordCount = 1; i < sentence.size(); wordCount++){
            for(j = 0; i < sentence.size() && j < searchWord.size() && sentence[i] == searchWord[j]; i++, j++);

            if(j >= searchWord.size())
                return wordCount;
            
            while(i < sentence.size() && sentence[i++] != ' ');
        }

        return -1;
    }
};