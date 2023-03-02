class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = ' '; //out of chars list
        int count = 0; // so count > 1 doesn't freak out
        int i = 0;

        for(char & c : chars){
            if(prev == c)
                count++;
            else{
                if(count > 1)
                    charToInt(chars, i, count);

                prev = c;
                chars[i++] = c;
                count = 1;
            }
        }

        if(count > 1) //check for tailing char
            charToInt(chars, i, count);

        chars.resize(i);

        return chars.size();
    }

    void charToInt(vector<char>& v, int& i, int& count){
        string s = to_string(count);

        for(char & c : s)
            v[i++] = c;
    }
};