class Solution {
public:
    string reversePrefix(string &word, char ch) {
        int r = 0, l = 0;
        for(; r < word.size() && word[r] != ch; r++);

        if(r >= word.size())
            return word;

        while(l < r)
            swap(word[l++], word[r--]);

        return word;
    }
};