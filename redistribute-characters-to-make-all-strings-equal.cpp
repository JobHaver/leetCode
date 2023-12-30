class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> alph(26);

        for(string &s : words){
            for(char c : s)
                alph[c - 'a']++;
        }

        int size = words.size();
        for(int i : alph){
            if(i % size != 0)
                return false;
        }

        return true;
    }
};