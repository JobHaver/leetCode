class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::stringstream ss;

        for(int i = 0, j = 0; i < s.size(); i++){
            if(j < spaces.size() && i == spaces[j]){
                ss << ' ';
                j++;
            }

            ss << s[i];
        }

        return ss.str();
    }
};