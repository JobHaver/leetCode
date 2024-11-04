class Solution {
public:
    string compressedString(string word) {
        stringstream ss;

        for(int i = 0, j; i < word.size(); i += j){
            for(j = 0; i + j < word.size() && j < 9 && word[i] == word[i + j]; j++);

            ss << j << word[i];
        }

        return ss.str();
    }
};