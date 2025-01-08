class Solution {
private:
    bool isSubstring(string &substring, string &word){
        for(int curr = 0; curr < word.size() && word.size() - curr >= substring.size(); curr++){
            int j = 0;
            for(int i = curr; j < substring.size() && substring[j] == word[i]; i++, j++);

            if(j == substring.size())
                return true;
        }

        return false;
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i != j && isSubstring(words[i], words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};