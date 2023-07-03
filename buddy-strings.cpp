class Solution {
private:
    int alphSize = 26;

    bool duplicates(vector<int> &alph){
        for(int i = 0; i < alphSize; i++){
            if(alph[i] > 1)
                return true;
        }

        return false;
    }


public:
    bool buddyStrings(string s, string goal) {
        vector<int> alphabet(alphSize), diff;

        if(s.size() != goal.size())
            return false;

        for(int i = 0; i < s.size(); i++){
            alphabet[s[i] - 'a']++;

            if(s[i] != goal[i]){
                diff.push_back(i);
                if(diff.size() > 2)
                    return false;
            }
        }

        return diff.empty() ? duplicates(alphabet) : diff.size() == 1 ? false : (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]);
    }
};