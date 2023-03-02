class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        char prev = ' '; //out of chars list
        int count = 0; // so count > 1 doesn't freak out

        for(char & c : chars){
            if(prev == c)
                count++;
            else{
                if(count > 1)
                    charToInt(ans, count);

                prev = c;
                ans.push_back(c);
                count = 1;
            }
        }

        if(count > 1) //check for tailing char
            charToInt(ans, count);

        chars = ans;

        return chars.size();
    }

    void charToInt(vector<char>& v, int& count){
        string s = to_string(count);

        for(auto & c : s)
            v.push_back(c);
    }
};